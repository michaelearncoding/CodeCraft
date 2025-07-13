# 🚀 环境搭建指南

这个指南将帮助你逐步搭建分布式数据同步平台的开发环境。

## 📋 前置要求

### 必需软件
- **Docker Desktop**: 20.10+ (确保已启动)
- **Git**: 2.30+
- **终端**: macOS Terminal, Windows PowerShell, 或 Linux Terminal

### 系统要求
- **内存**: 至少 8GB RAM (推荐 16GB+)
- **存储**: 至少 10GB 可用空间
- **网络**: 稳定的互联网连接

## 🛠️ 分步骤搭建

### 第一步：启动基础环境

基础环境包含核心的数据存储和消息队列服务：

```bash
# 启动基础服务
./start-basic.sh
```

这将启动：
- **PostgreSQL** (端口 5432) - 主数据库
- **Redis** (端口 6379) - 缓存和会话存储
- **Kafka** (端口 9092) - 消息队列
- **Zookeeper** (端口 2181) - Kafka的协调服务

### 第二步：启动监控环境（可选）

监控环境用于观察系统运行状态：

```bash
# 启动监控服务
./start-monitoring.sh
```

这将启动：
- **Grafana** (端口 3000) - 监控图表界面
- **Kibana** (端口 5601) - 日志分析界面
- **Prometheus** (端口 9090) - 监控数据收集
- **Elasticsearch** (端口 9200) - 日志和监控数据存储

## 📊 访问地址

### 基础服务
- **PostgreSQL**: `localhost:5432`
  - 数据库: `datasync`
  - 用户名: `datasync`
  - 密码: `datasync123`

- **Redis**: `localhost:6379`

- **Kafka**: `localhost:9092`

### 监控服务
- **Grafana**: http://localhost:3000
  - 用户名: `admin`
  - 密码: `admin`

- **Kibana**: http://localhost:5601

- **Prometheus**: http://localhost:9090

- **Elasticsearch**: http://localhost:9200

## 🔧 常用命令

### 查看服务状态
```bash
# 查看基础服务状态
docker-compose -f docker-compose-basic.yml ps

# 查看监控服务状态
docker-compose -f docker-compose-monitoring.yml ps
```

### 查看日志
```bash
# 查看所有基础服务日志
docker-compose -f docker-compose-basic.yml logs -f

# 查看特定服务日志
docker-compose -f docker-compose-basic.yml logs -f postgres
docker-compose -f docker-compose-basic.yml logs -f redis
docker-compose -f docker-compose-basic.yml logs -f kafka
```

### 停止服务
```bash
# 停止基础服务
docker-compose -f docker-compose-basic.yml down

# 停止监控服务
docker-compose -f docker-compose-monitoring.yml down

# 停止所有服务并清理数据
docker-compose -f docker-compose-basic.yml down -v
docker-compose -f docker-compose-monitoring.yml down -v
```

### 重启服务
```bash
# 重启特定服务
docker-compose -f docker-compose-basic.yml restart postgres
docker-compose -f docker-compose-basic.yml restart redis
```

## 🧪 验证环境

### 验证PostgreSQL
```bash
# 连接数据库
docker exec -it datasync-postgres psql -U datasync -d datasync

# 在psql中执行
\dt  # 查看表
SELECT version();  # 查看版本
\q  # 退出
```

### 验证Redis
```bash
# 连接Redis
docker exec -it datasync-redis redis-cli

# 在redis-cli中执行
ping  # 应该返回 PONG
set test "hello"  # 设置值
get test  # 获取值
exit  # 退出
```

### 验证Kafka
```bash
# 查看Kafka主题
docker exec -it datasync-kafka kafka-topics --bootstrap-server localhost:9092 --list

# 创建测试主题
docker exec -it datasync-kafka kafka-topics --bootstrap-server localhost:9092 --create --topic test-topic --partitions 1 --replication-factor 1
```

## 🐛 常见问题

### 1. 端口冲突
如果遇到端口被占用的错误：
```bash
# 查看端口占用
lsof -i :5432
lsof -i :6379
lsof -i :9092

# 停止占用端口的进程
sudo kill -9 <PID>
```

### 2. 内存不足
如果Docker容器启动失败：
- 在Docker Desktop中增加内存限制到8GB+
- 或者只启动基础服务，不启动监控服务

### 3. 服务启动慢
- Elasticsearch 启动需要2-3分钟，这是正常的
- 可以通过日志查看启动进度：
```bash
docker-compose -f docker-compose-monitoring.yml logs -f elasticsearch
```

### 4. 网络问题
如果容器间无法通信：
```bash
# 检查网络
docker network ls
docker network inspect distributed-data-sync-platform_datasync-network
```

## 📚 下一步

环境搭建完成后，你可以：

1. **开始后端开发**：
   ```bash
   cd backend
   ./gradlew bootRun
   ```

2. **开始前端开发**：
   ```bash
   cd frontend
   npm install
   npm start
   ```

3. **学习监控工具**：
   - 访问 Grafana 创建仪表板
   - 访问 Kibana 查看日志
   - 访问 Prometheus 查看指标

4. **阅读项目文档**：
   - [README.md](README.md) - 项目概述
   - [IMPLEMENTATION_PLAN.md](docs/IMPLEMENTATION_PLAN.md) - 实施计划

## 💡 提示

- **循序渐进**：先启动基础环境，熟悉后再启动监控环境
- **资源管理**：监控环境会占用较多资源，开发时可以选择性启动
- **数据持久化**：所有数据都保存在Docker卷中，重启不会丢失
- **学习路径**：建议先熟悉基础服务，再学习监控工具的使用 