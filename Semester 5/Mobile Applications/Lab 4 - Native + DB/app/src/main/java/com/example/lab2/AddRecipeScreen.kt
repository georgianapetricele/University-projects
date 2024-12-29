package com.example.lab2

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.unit.dp

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun AddRecipeScreen(
    recipeViewModel: RecipeViewModel,
    onRecipeAdded: () -> Unit
) {
    var name by remember { mutableStateOf("") }
    var ingredients by remember { mutableStateOf("") }
    var preparationSteps by remember { mutableStateOf("") }
    var preparationTime by remember { mutableStateOf("") }

    var nameError by remember { mutableStateOf("") }
    var ingredientsError by remember { mutableStateOf("") }
    var preparationStepsError by remember { mutableStateOf("") }
    var preparationTimeError by remember { mutableStateOf("") }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        verticalArrangement = Arrangement.SpaceBetween,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = "Add New Recipe",
            style = MaterialTheme.typography.headlineMedium,
            color = MaterialTheme.colorScheme.primary
        )

        Text(text = "Recipe Name", style = MaterialTheme.typography.bodyMedium)
        TextField(
            value = name,
            onValueChange = {
                name = it
                nameError = ""
            },
            modifier = Modifier
                .fillMaxWidth()
                .padding(vertical = 4.dp),
            isError = nameError.isNotEmpty()
        )
        if (nameError.isNotEmpty()) {
            Text(
                text = nameError,
                color = MaterialTheme.colorScheme.error,
                style = MaterialTheme.typography.bodySmall,
                modifier = Modifier.padding(start = 8.dp)
            )
        }

        Text(text = "Ingredients", style = MaterialTheme.typography.bodyMedium)
        TextField(
            value = ingredients,
            onValueChange = {
                ingredients = it
                ingredientsError = ""
            },
            modifier = Modifier
                .fillMaxWidth()
                .padding(vertical = 4.dp),
            isError = ingredientsError.isNotEmpty()
        )
        if (ingredientsError.isNotEmpty()) {
            Text(
                text = ingredientsError,
                color = MaterialTheme.colorScheme.error,
                style = MaterialTheme.typography.bodySmall,
                modifier = Modifier.padding(start = 8.dp)
            )
        }

        Text(text = "Preparation Steps", style = MaterialTheme.typography.bodyMedium)
        TextField(
            value = preparationSteps,
            onValueChange = {
                preparationSteps = it
                preparationStepsError = ""
            },
            modifier = Modifier
                .fillMaxWidth()
                .padding(vertical = 4.dp),
            isError = preparationStepsError.isNotEmpty()
        )
        if (preparationStepsError.isNotEmpty()) {
            Text(
                text = preparationStepsError,
                color = MaterialTheme.colorScheme.error,
                style = MaterialTheme.typography.bodySmall,
                modifier = Modifier.padding(start = 8.dp)
            )
        }

        Text(text = "Preparation Time (minutes)", style = MaterialTheme.typography.bodyMedium)
        TextField(
            value = preparationTime,
            onValueChange = {
                preparationTime = it
                preparationTimeError = ""
            },
            modifier = Modifier
                .fillMaxWidth()
                .padding(vertical = 4.dp),
            keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
            isError = preparationTimeError.isNotEmpty()
        )
        if (preparationTimeError.isNotEmpty()) {
            Text(
                text = preparationTimeError,
                color = MaterialTheme.colorScheme.error,
                style = MaterialTheme.typography.bodySmall,
                modifier = Modifier.padding(start = 8.dp)
            )
        }

        Button(
            onClick = {
                var hasError = false
                if (name.isEmpty()) {
                    nameError = "Recipe Name cannot be empty."
                    hasError = true
                }
                if (ingredients.isEmpty()) {
                    ingredientsError = "Ingredients cannot be empty."
                    hasError = true
                }
                if (preparationSteps.isEmpty()) {
                    preparationStepsError = "Preparation Steps cannot be empty."
                    hasError = true
                }
                if (preparationTime.toIntOrNull() == null || preparationTime.toInt() <= 0) {
                    preparationTimeError = "Preparation time must be a positive number."
                    hasError = true
                }
                if (!hasError) {
                    val recipe = Recipe(
                        name = name,
                        ingredients = ingredients,
                        preparationSteps = preparationSteps,
                        preparationTime = preparationTime.toInt()
                    )
                    recipeViewModel.addRecipe(recipe)
                    onRecipeAdded()
                }
            },
            colors = ButtonDefaults.buttonColors(
                containerColor = MaterialTheme.colorScheme.primary,
                contentColor = MaterialTheme.colorScheme.tertiary
            ),
            modifier = Modifier.padding(top = 16.dp)
        ) {
            Text(text = "Add Recipe")
        }
    }
}
