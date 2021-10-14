// Top-level build file where you can add configuration options common to all sub-projects/modules.
buildscript {
    repositories {
        google()
        mavenCentral()
    }
    dependencies {
        classpath("com.android.tools.build:gradle:7.0.1")
        classpath("org.jetbrains.kotlin:kotlin-gradle-plugin:1.5.20")
    }
}

/*tasks.register("clean", Delete::class) {
    delete(rootProject.buildDir)
}*/

plugins {
    id("com.diffplug.spotless") version "5.14.2"
}

spotless {
    val copyRightFile = rootProject.file("spotless/copyright.kt")
    kotlin {
        target("**/src/**/*.kt")
        targetExclude("$buildDir/**/*.kt", "**/cpp/libretro-common/**", "**/cpp/oboe/**")
        ktlint("0.41.0").userData(mapOf("android" to "true"))
        licenseHeaderFile(copyRightFile, "^(package|//startfile|@file)")
    }
    cpp {
        target("**/src/**/*.cpp", "**/src/**/*.c", "**/src/**/*.h")
        targetExclude("**/cpp/libretro-common/**", "**/cpp/oboe/**")
        licenseHeaderFile(copyRightFile)
    }
}