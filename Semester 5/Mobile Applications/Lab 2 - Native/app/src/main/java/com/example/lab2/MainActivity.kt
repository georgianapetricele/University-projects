package com.example.lab2

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import androidx.lifecycle.ViewModelProvider
import com.example.lab2.ui.theme.Lab2Theme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        val recipeViewModel = ViewModelProvider(this)[RecipeViewModel::class.java]

        setContent {
            Lab2Theme {
                var showAddRecipeScreen by remember { mutableStateOf(false) }
                var recipeToEdit by remember { mutableStateOf<Recipe?>(null) }

                if (showAddRecipeScreen) {
                    AddRecipeScreen(
                        recipeViewModel = recipeViewModel,
                        onRecipeAdded = { showAddRecipeScreen = false }
                    )
                } else if (recipeToEdit != null) {
                    UpdateRecipeScreen(
                        recipe = recipeToEdit!!,
                        onUpdate = { updatedRecipe ->
                            recipeViewModel.updateRecipe(updatedRecipe)
                            recipeToEdit = null
                        },
                        onCancel = { recipeToEdit = null }
                    )
                } else {
                    MainScreen(recipeViewModel, {
                        showAddRecipeScreen = true
                    }, { recipe ->
                        recipeToEdit = recipe
                    })
                }
            }
        }
    }

    @Composable
    fun MainScreen(
        recipeViewModel: RecipeViewModel,
        onAddRecipeClicked: () -> Unit,
        onEditRecipe: (Recipe) -> Unit
    ) {

        val recipes by recipeViewModel.recipes.observeAsState(emptyList())

        Scaffold(
            topBar = { TopBar() },
            bottomBar = { BottomBar(onAddRecipeClicked) },
            content = { padding ->
                Box(
                    modifier = Modifier
                        .fillMaxSize()
                        .padding(padding)
                ) {
                    RecipeListScreen(
                        recipes = recipes,
                        onDeleteRecipeById = { id -> recipeViewModel.removeRecipeById(id) },
                        onEditRecipe = { recipe -> onEditRecipe(recipe) }
                    )
                }
            }
        )
    }

    @Composable
    fun TopBar() {
        Box(
            modifier = Modifier
                .fillMaxWidth()
                .background(MaterialTheme.colorScheme.tertiary)
                .padding(vertical = 16.dp),
            contentAlignment = Alignment.Center
        ) {
            Text(
                text = "MY RECIPES",
                color = MaterialTheme.colorScheme.primary,
                style = MaterialTheme.typography.headlineMedium
            )
        }
    }

    @Composable
    fun BottomBar(onAddRecipeClicked: () -> Unit) {
        Box(
            modifier = Modifier
                .fillMaxWidth()
                .background(MaterialTheme.colorScheme.tertiary)
                .padding(vertical = 1.dp),
            contentAlignment = Alignment.Center
        ) {
            IconButton(
                onClick = onAddRecipeClicked,
                modifier = Modifier.size(60.dp)
            ) {
                Icon(
                    painter = painterResource(id = R.drawable.baseline_add_circle_outline_24),
                    contentDescription = "Add Recipe",
                    tint = MaterialTheme.colorScheme.primary,
                    modifier = Modifier.size(60.dp)
                )
            }
        }
    }
}
