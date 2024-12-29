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
fun UpdateRecipeScreen(
    recipe: Recipe,
    onUpdate: (Recipe) -> Unit,
    onCancel: () -> Unit
) {
    var name by remember { mutableStateOf(recipe.name) }
    var ingredients by remember { mutableStateOf(recipe.ingredients) }
    var preparationSteps by remember { mutableStateOf(recipe.preparationSteps) }
    var preparationTime by remember { mutableStateOf(recipe.preparationTime.toString()) }

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
            text = "Update Recipe",
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
                style = MaterialTheme.typography.bodySmall
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
                style = MaterialTheme.typography.bodySmall
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
                style = MaterialTheme.typography.bodySmall
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
                style = MaterialTheme.typography.bodySmall
            )
        }

        Row(
            modifier = Modifier.padding(top = 16.dp),
            horizontalArrangement = Arrangement.spacedBy(16.dp)
        ) {
            Button(
                onClick = {
                    nameError = ""
                    ingredientsError = ""
                    preparationStepsError = ""
                    preparationTimeError = ""

                    val preparationTimeInt = preparationTime.toIntOrNull()

                    when {
                        name.isEmpty() -> nameError = "Recipe name cannot be empty."
                        ingredients.isEmpty() -> ingredientsError = "Ingredients cannot be empty."
                        preparationSteps.isEmpty() -> preparationStepsError = "Preparation steps cannot be empty."
                        preparationTime.isEmpty() || preparationTimeInt == null || preparationTimeInt < 0 ->
                            preparationTimeError = "Preparation time must be a non-negative number."
                        else -> {
                            val updatedRecipe = recipe.copy(
                                name = name,
                                ingredients = ingredients,
                                preparationSteps = preparationSteps,
                                preparationTime = preparationTimeInt
                            )
                            onUpdate(updatedRecipe)
                        }
                    }
                },
                colors = ButtonDefaults.buttonColors(
                    containerColor = MaterialTheme.colorScheme.primary,
                    contentColor = MaterialTheme.colorScheme.tertiary
                )
            ) {
                Text("Update")
            }

            Button(
                onClick = onCancel,
                colors = ButtonDefaults.buttonColors(
                    containerColor = MaterialTheme.colorScheme.primary,
                    contentColor = MaterialTheme.colorScheme.tertiary
                )
            ) {
                Text("Cancel")
            }
        }
    }
}
