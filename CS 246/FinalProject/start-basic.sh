#!/bin/bash

echo "🚀 启动分布式数据同步平台 - 基础环境"
echo "=================================="

# 检查Docker是否运行
if ! docker info > /dev/null 2>&1; then
    echo "❌ Docker未运行，请先启动Docker"
    exit 1
fi

echo "📦 启动基础服务 (PostgreSQL, Redis, Kafka, Zookeeper)..."
docker-compose -f docker-compose-basic.yml up -d

echo "⏳ 等待服务启动..."
sleep 10

echo "🔍 检查服务状态..."
docker-compose -f docker-compose-basic.yml ps

echo "✅ 基础环境启动完成！"
echo ""
echo "📊 服务访问地址："
echo "  PostgreSQL: localhost:5432"
echo "  Redis: localhost:6379"
echo "  Kafka: localhost:9092"
echo ""
echo "🔧 常用命令："
echo "  查看日志: docker-compose -f docker-compose-basic.yml logs -f"
echo "  停止服务: docker-compose -f docker-compose-basic.yml down"
echo "  重启服务: docker-compose -f docker-compose-basic.yml restart" 