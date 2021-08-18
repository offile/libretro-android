// Top-level build file where you can add configuration options common to all sub-projects/modules.
buildscript {
    repositories {
        google()
        mavenCentral()
    }
    dependencies {
        classpath("com.android.tools.build:gradle:7.0.0")
        classpath("org.jetbrains.kotlin:kotlin-gradle-plugin:1.5.10")
    }
}

/*tasks.register("clean", Delete::class) {
    delete(rootProject.buildDir)
}*/

plugins {
    id("com.diffplug.spotless") version "5.14.2"
}

spotless {
    kotlin {
        target("*/src/*/java/**/*.kt")
        targetExclude("$buildDir/**/*.kt")
        ktlint("0.41.0")
        //licenseHeaderFile(rootProject.file("spotless/copyright.kt"))
    }
}