package com.example.lab2

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

class RecipeViewModel : ViewModel() {
    //private val repository = RecipeRepository()

    //private val _recipes = MutableLiveData<List<Recipe>>(emptyList())
    //val recipes: LiveData<List<Recipe>> get() = _recipes

    val recipeDao = MainApplication.recipeDatabase.getRecipeDao()

    val recipes: LiveData<List<Recipe>> = recipeDao.getAllRecipes()

//    init {
//        _recipes.value = repository.getRecipes()
//    }

    fun addRecipe(recipe: Recipe) {

        viewModelScope.launch(Dispatchers.IO) {
            recipeDao.addRecipe(recipe)
        }
    }


    fun removeRecipeById(id: Int) {
        viewModelScope.launch(Dispatchers.IO) {
            recipeDao.deleteRecipe(id)
        }
    }

    fun updateRecipe(updatedRecipe: Recipe) {
        viewModelScope.launch(Dispatchers.IO) {
            recipeDao.updateRecipe(updatedRecipe)
        }
    }
}
