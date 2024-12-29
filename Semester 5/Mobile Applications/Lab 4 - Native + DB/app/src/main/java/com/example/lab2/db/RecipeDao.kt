package com.example.lab2.db

import androidx.lifecycle.LiveData
import androidx.room.Dao
import androidx.room.Insert
import androidx.room.Query
import androidx.room.Update
import com.example.lab2.Recipe

@Dao
interface RecipeDao {

    @Query("SELECT * FROM recipe")
    fun getAllRecipes(): LiveData<List<Recipe>>

    @Insert
    fun addRecipe(recipe: Recipe)

    @Update
    fun updateRecipe(recipe: Recipe)


    @Query("DELETE FROM recipe WHERE id = :id")
    fun deleteRecipe(id: Int)
}