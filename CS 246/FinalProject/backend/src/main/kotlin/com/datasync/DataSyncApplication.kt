package com.datasync

import org.springframework.boot.autoconfigure.SpringBootApplication
import org.springframework.boot.runApplication
import org.springframework.scheduling.annotation.EnableAsync
import org.springframework.scheduling.annotation.EnableScheduling
import org.springframework.transaction.annotation.EnableTransactionManagement

/**
 * 分布式数据同步平台主应用类
 * 
 * 体现CS 346的Kotlin应用开发特点：
 * - Spring Boot应用配置
 * - 异步处理支持
 * - 定时任务支持
 * - 事务管理
 * 
 * @author DataSync Team
 * @version 1.0.0
 */
@SpringBootApplication
@EnableAsync
@EnableScheduling
@EnableTransactionManagement
class DataSyncApplication

/**
 * 应用程序入口点
 */
fun main(args: Array<String>) {
    runApplication<DataSyncApplication>(*args)
} 