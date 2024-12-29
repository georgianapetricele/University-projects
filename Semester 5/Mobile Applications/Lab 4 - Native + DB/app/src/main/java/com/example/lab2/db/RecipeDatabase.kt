package com.example.lab2.db

import androidx.room.Database
import androidx.room.RoomDatabase
import com.example.lab2.Recipe

@Database(entities = [Recipe::class], version = 1)
abstract class RecipeDatabase : RoomDatabase() {

    companion object{
        const val NAME="recipe_db"
    }

    abstract fun getRecipeDao(): RecipeDao
}