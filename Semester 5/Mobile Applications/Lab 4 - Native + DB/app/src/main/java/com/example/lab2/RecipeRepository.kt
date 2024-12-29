package com.example.lab2

class RecipeRepository {
    private val recipes = mutableListOf(
        Recipe( id = 1,
            name = "Spaghetti Carbonara",
            ingredients = "Spaghetti, eggs, pancetta, Parmesan cheese, pepper",
            preparationSteps = "1. Boil spaghetti. 2. Fry pancetta. 3. Mix eggs and cheese. 4. Combine and season.",
            preparationTime = 20),
        Recipe(id = 2,
            name = "Classic Pancakes",
            ingredients = "Flour, milk, eggs, sugar, butter, baking powder",
            preparationSteps = "1. Mix dry ingredients. 2. Whisk in milk and eggs. 3. Cook on griddle.",
            preparationTime = 15),
    )

    fun getRecipes(): List<Recipe> = recipes

    fun addRecipe(recipe: Recipe) {
        recipes.add(recipe)

    }

    fun removeRecipeById(id: Int) {
        recipes.removeIf { it.id == id }
    }

    fun updateRecipe(updatedRecipe: Recipe) {
        val index = recipes.indexOfFirst { it.id == updatedRecipe.id }
        if (index != -1) {
            recipes[index] = updatedRecipe
        }
    }

    fun getNextId(): Int = (recipes.maxOfOrNull { it.id } ?: 0) + 1
}