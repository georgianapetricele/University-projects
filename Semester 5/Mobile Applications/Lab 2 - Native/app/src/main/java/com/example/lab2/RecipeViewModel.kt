package com.example.lab2

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel

class RecipeViewModel : ViewModel() {
    private val repository = RecipeRepository()

    private val _recipes = MutableLiveData<List<Recipe>>(emptyList())
    val recipes: LiveData<List<Recipe>> get() = _recipes

    init {
        _recipes.value = repository.getRecipes()
    }

    fun addRecipe(recipe: Recipe) {
        repository.addRecipe(recipe)
        _recipes.value = repository.getRecipes()
    }


    fun removeRecipeById(id: Int) {
        repository.removeRecipeById(id)
        _recipes.value = repository.getRecipes()
    }

    fun updateRecipe(updatedRecipe: Recipe) {
        repository.updateRecipe(updatedRecipe)
        _recipes.value = repository.getRecipes()
    }


    fun getNextId(): Int {
        return repository.getNextId()
    }
}
