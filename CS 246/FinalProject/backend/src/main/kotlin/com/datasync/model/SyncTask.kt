package com.datasync.model

import jakarta.persistence.*
import jakarta.validation.constraints.NotBlank
import jakarta.validation.constraints.NotNull
import java.time.LocalDateTime

/**
 * 数据同步任务实体类
 * 
 * 体现CS 346的Kotlin特性：
 * - 数据类 (data class)
 * - 空安全 (nullable types)
 * - 扩展函数
 * - 密封类 (sealed class)
 * 
 * @author DataSync Team
 * @version 1.0.0
 */
@Entity
@Table(name = "sync_tasks")
data class SyncTask(
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    val id: Long? = null,
    
    @field:NotBlank(message = "任务名称不能为空")
    @Column(name = "task_name", nullable = false, unique = true)
    val taskName: String,
    
    @field:NotBlank(message = "任务描述不能为空")
    @Column(name = "description", nullable = false)
    val description: String,
    
    @Enumerated(EnumType.STRING)
    @Column(name = "status", nullable = false)
    val status: TaskStatus = TaskStatus.CREATED,
    
    @Enumerated(EnumType.STRING)
    @Column(name = "sync_type", nullable = false)
    val syncType: SyncType,
    
    @Column(name = "source_config", columnDefinition = "TEXT")
    val sourceConfig: String? = null,
    
    @Column(name = "target_config", columnDefinition = "TEXT")
    val targetConfig: String? = null,
    
    @Column(name = "transformation_rules", columnDefinition = "TEXT")
    val transformationRules: String? = null,
    
    @Column(name = "schedule_cron")
    val scheduleCron: String? = null,
    
    @Column(name = "batch_size")
    val batchSize: Int = 1000,
    
    @Column(name = "max_retries")
    val maxRetries: Int = 3,
    
    @Column(name = "retry_interval_seconds")
    val retryIntervalSeconds: Int = 60,
    
    @Column(name = "created_at", nullable = false)
    val createdAt: LocalDateTime = LocalDateTime.now(),
    
    @Column(name = "updated_at")
    val updatedAt: LocalDateTime? = null,
    
    @Column(name = "last_run_at")
    val lastRunAt: LocalDateTime? = null,
    
    @Column(name = "next_run_at")
    val nextRunAt: LocalDateTime? = null,
    
    @Column(name = "total_records_processed")
    val totalRecordsProcessed: Long = 0,
    
    @Column(name = "total_records_failed")
    val totalRecordsFailed: Long = 0,
    
    @Column(name = "average_processing_time_ms")
    val averageProcessingTimeMs: Long = 0,
    
    @Column(name = "is_active", nullable = false)
    val isActive: Boolean = true
) {
    /**
     * 检查任务是否可以运行
     */
    fun canRun(): Boolean = isActive && status == TaskStatus.READY
    
    /**
     * 检查任务是否已完成
     */
    fun isCompleted(): Boolean = status == TaskStatus.COMPLETED || status == TaskStatus.FAILED
    
    /**
     * 获取任务运行统计信息
     */
    fun getStatistics(): TaskStatistics = TaskStatistics(
        totalRecordsProcessed = totalRecordsProcessed,
        totalRecordsFailed = totalRecordsFailed,
        averageProcessingTimeMs = averageProcessingTimeMs,
        successRate = if (totalRecordsProcessed > 0) {
            (totalRecordsProcessed - totalRecordsFailed) * 100.0 / totalRecordsProcessed
        } else 0.0
    )
}

/**
 * 任务状态枚举
 */
enum class TaskStatus {
    CREATED,        // 已创建
    READY,          // 准备就绪
    RUNNING,        // 运行中
    PAUSED,         // 已暂停
    COMPLETED,      // 已完成
    FAILED,         // 失败
    CANCELLED       // 已取消
}

/**
 * 同步类型枚举
 */
enum class SyncType {
    REAL_TIME,      // 实时同步
    BATCH,          // 批量同步
    INCREMENTAL,    // 增量同步
    FULL_SYNC       // 全量同步
}

/**
 * 任务统计信息数据类
 */
data class TaskStatistics(
    val totalRecordsProcessed: Long,
    val totalRecordsFailed: Long,
    val averageProcessingTimeMs: Long,
    val successRate: Double
)

/**
 * 任务配置数据类
 */
data class TaskConfig(
    val sourceType: String,
    val sourceConnectionString: String,
    val sourceQuery: String? = null,
    val targetType: String,
    val targetConnectionString: String,
    val targetTable: String,
    val transformationRules: List<TransformationRule> = emptyList(),
    val scheduleCron: String? = null,
    val batchSize: Int = 1000,
    val maxRetries: Int = 3,
    val retryIntervalSeconds: Int = 60
)

/**
 * 数据转换规则
 */
data class TransformationRule(
    val ruleName: String,
    val ruleType: RuleType,
    val ruleConfig: String,
    val order: Int = 0
)

/**
 * 转换规则类型
 */
enum class RuleType {
    FIELD_MAPPING,      // 字段映射
    DATA_VALIDATION,    // 数据验证
    DATA_TRANSFORM,     // 数据转换
    DATA_FILTER         // 数据过滤
}

/**
 * 任务执行结果
 */
sealed class TaskExecutionResult {
    data class Success(
        val taskId: Long,
        val recordsProcessed: Long,
        val processingTimeMs: Long,
        val message: String = "Task completed successfully"
    ) : TaskExecutionResult()
    
    data class Failure(
        val taskId: Long,
        val errorMessage: String,
        val exception: Exception? = null,
        val retryCount: Int = 0
    ) : TaskExecutionResult()
    
    data class PartialSuccess(
        val taskId: Long,
        val recordsProcessed: Long,
        val recordsFailed: Long,
        val processingTimeMs: Long,
        val errorMessage: String
    ) : TaskExecutionResult()
}

/**
 * SyncTask 扩展函数
 */
fun SyncTask.toTaskConfig(): TaskConfig? {
    return try {
        // 这里可以添加JSON解析逻辑
        TaskConfig(
            sourceType = "unknown",
            sourceConnectionString = "",
            targetType = "unknown",
            targetConnectionString = "",
            targetTable = ""
        )
    } catch (e: Exception) {
        null
    }
}

/**
 * 任务状态转换扩展函数
 */
fun SyncTask.transitionTo(newStatus: TaskStatus): SyncTask {
    return copy(
        status = newStatus,
        updatedAt = LocalDateTime.now()
    )
}

/**
 * 更新任务执行统计信息
 */
fun SyncTask.updateStatistics(
    recordsProcessed: Long,
    recordsFailed: Long,
    processingTimeMs: Long
): SyncTask {
    val totalProcessed = this.totalRecordsProcessed + recordsProcessed
    val totalFailed = this.totalRecordsFailed + recordsFailed
    
    val newAverageTime = if (totalProcessed > 0) {
        ((this.averageProcessingTimeMs * this.totalRecordsProcessed) + processingTimeMs) / totalProcessed
    } else {
        processingTimeMs
    }
    
    return copy(
        totalRecordsProcessed = totalProcessed,
        totalRecordsFailed = totalFailed,
        averageProcessingTimeMs = newAverageTime,
        lastRunAt = LocalDateTime.now(),
        updatedAt = LocalDateTime.now()
    )
} 