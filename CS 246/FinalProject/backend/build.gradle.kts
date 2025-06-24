import org.jetbrains.kotlin.gradle.tasks.KotlinCompile

plugins {
    id("org.springframework.boot") version "3.2.0"
    id("io.spring.dependency-management") version "1.1.4"
    kotlin("jvm") version "1.9.20"
    kotlin("plugin.spring") version "1.9.20"
    kotlin("plugin.jpa") version "1.9.20"
    kotlin("plugin.allopen") version "1.9.20"
    kotlin("plugin.noarg") version "1.9.20"
}

group = "com.datasync"
version = "1.0.0"
java.sourceCompatibility = JavaVersion.VERSION_17

repositories {
    mavenCentral()
    maven { url = uri("https://repo.spring.io/milestone") }
    maven { url = uri("https://repo.spring.io/snapshot") }
}

dependencies {
    // Spring Boot 核心
    implementation("org.springframework.boot:spring-boot-starter-web")
    implementation("org.springframework.boot:spring-boot-starter-data-jpa")
    implementation("org.springframework.boot:spring-boot-starter-data-redis")
    implementation("org.springframework.boot:spring-boot-starter-validation")
    implementation("org.springframework.boot:spring-boot-starter-actuator")
    implementation("org.springframework.boot:spring-boot-starter-websocket")
    
    // Kotlin
    implementation("com.fasterxml.jackson.module:jackson-module-kotlin")
    implementation("org.jetbrains.kotlin:kotlin-reflect")
    implementation("org.jetbrains.kotlin:kotlin-stdlib-jdk8")
    
    // 数据库
    implementation("org.postgresql:postgresql")
    implementation("org.flywaydb:flyway-core")
    
    // 消息队列
    implementation("org.springframework.kafka:spring-kafka")
    
    // gRPC
    implementation("io.grpc:grpc-netty-shaded:1.59.0")
    implementation("io.grpc:grpc-protobuf:1.59.0")
    implementation("io.grpc:grpc-stub:1.59.0")
    implementation("net.devh:grpc-server-spring-boot-starter:2.15.0.RELEASE")
    implementation("net.devh:grpc-client-spring-boot-starter:2.15.0.RELEASE")
    
    // 监控和指标
    implementation("io.micrometer:micrometer-registry-prometheus")
    implementation("io.micrometer:micrometer-core")
    
    // 工具库
    implementation("org.apache.commons:commons-lang3:3.12.0")
    implementation("com.google.guava:guava:32.1.3-jre")
    implementation("org.apache.commons:commons-pool2:2.11.1")
    
    // 测试
    testImplementation("org.springframework.boot:spring-boot-starter-test")
    testImplementation("org.springframework.kafka:spring-kafka-test")
    testImplementation("org.testcontainers:junit-jupiter:1.19.3")
    testImplementation("org.testcontainers:postgresql:1.19.3")
    testImplementation("org.testcontainers:kafka:1.19.3")
    testImplementation("io.mockk:mockk:1.13.8")
    testImplementation("org.jetbrains.kotlin:kotlin-test-junit5")
}

tasks.withType<KotlinCompile> {
    kotlinOptions {
        freeCompilerArgs += "-Xjsr305=strict"
        jvmTarget = "17"
    }
}

tasks.withType<Test> {
    useJUnitPlatform()
    testLogging {
        events("passed", "skipped", "failed")
    }
}

// 代码质量检查
plugins {
    id("org.jlleitschuh.gradle.ktlint") version "11.6.1"
    id("io.gitlab.arturbosch.detekt") version "1.23.4"
}

ktlint {
    android.set(false)
    verbose.set(true)
    filter {
        exclude { element -> element.file.path.contains("build/") }
    }
}

detekt {
    config = files("$projectDir/config/detekt/detekt.yml")
    buildUponDefaultConfig = true
    allRules = false
}

// Docker 支持
plugins {
    id("com.palantir.docker") version "0.35.0"
}

docker {
    name = "${project.name}:${project.version}"
    files("build/libs/${project.name}-${project.version}.jar")
    buildArgs(mapOf("JAR_FILE" to "${project.name}-${project.version}.jar"))
}

// 性能测试
tasks.register<Test>("performanceTest") {
    description = "Runs performance tests"
    group = "verification"
    
    useJUnitPlatform {
        includeTags("performance")
    }
    
    testLogging {
        events("passed", "skipped", "failed")
        showStandardStreams = true
    }
    
    reports {
        html.required.set(true)
        junitXml.required.set(true)
    }
}

// 代码覆盖率
plugins {
    id("jacoco")
}

jacoco {
    toolVersion = "0.8.11"
}

tasks.test {
    finalizedBy(tasks.jacocoTestReport)
}

tasks.jacocoTestReport {
    dependsOn(tasks.test)
    reports {
        xml.required.set(true)
        html.required.set(true)
    }
}

// 自定义任务
tasks.register("buildAndTest") {
    dependsOn("clean", "build", "test")
    description = "Clean, build and test the project"
}

tasks.register("buildAndDeploy") {
    dependsOn("buildAndTest", "docker")
    description = "Build, test and create Docker image"
} 