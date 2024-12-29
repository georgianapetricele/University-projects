package com.example.lab2

import android.app.Application
import androidx.room.Room
import com.example.lab2.db.RecipeDatabase

class MainApplication: Application() {

    companion object {
        lateinit var recipeDatabase: RecipeDatabase
    }

    override fun onCreate() {
        super.onCreate()
        recipeDatabase = Room.databaseBuilder(
            applicationContext,
            RecipeDatabase::class.java,
            RecipeDatabase.NAME
        ).build()
    }
}