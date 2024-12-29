package com.example.lab2

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.AlertDialogDefaults.containerColor
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.Icon
import androidx.compose.material3.ListItemDefaults.contentColor
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.painter.Painter
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp

@Composable
fun RecipeCard(
    recipe: Recipe,
    onEditRecipe: () -> Unit,
    onDeleteRecipe: (Int) -> Unit
) {
    Card(
        modifier = Modifier
            .fillMaxWidth()
            .padding(8.dp),
        elevation = CardDefaults.cardElevation(4.dp),
        shape = RoundedCornerShape(16.dp),
        colors = CardDefaults.cardColors(
            containerColor = MaterialTheme.colorScheme.secondary,
            contentColor = Color.Black// Set your b
        )
    ) {
        Column(modifier = Modifier.padding(16.dp)) {

            val recipeImage: Painter = painterResource(id = R.drawable.img)
            Image(
                painter = recipeImage,
                contentDescription = "Recipe Image",
                modifier = Modifier
                    .fillMaxWidth()
                    .height(200.dp)
                    .padding(bottom = 8.dp)
            )


            Text(
                text = recipe.name,
                style = MaterialTheme.typography.headlineSmall,
                fontSize = 22.sp
            )


            Text(
                text = "Preparation Time: ${recipe.preparationTime} minutes",
                style = MaterialTheme.typography.bodyMedium,
                fontSize = 17.sp
            )


            Row(
                modifier = Modifier.fillMaxWidth(),
                horizontalArrangement = Arrangement.SpaceBetween
            ) {
                Button(
                    onClick = onEditRecipe,
//                    colors = ButtonDefaults.buttonColors(
//                        containerColor = MaterialTheme.colorScheme.secondary, // Background color
//                        contentColor = MaterialTheme.colorScheme.tertiary // Text color
//                    )
                ) {
                    // Edit icon and text inside the button
                    Icon(
                        painter = painterResource(id = R.drawable.baseline_edit_24), // Replace with your edit icon resource
                        contentDescription = "Edit",
                        modifier = Modifier.size(20.dp) // Icon size
                    )

                }


                Button(
                    onClick = { onDeleteRecipe(recipe.id) },
//                    colors = ButtonDefaults.buttonColors(
//                        containerColor = MaterialTheme.colorScheme.secondary, // Red background for delete
//                        contentColor = MaterialTheme.colorScheme.tertiary // White text color
//                    )
                ) {
                    Icon(
                        painter = painterResource(id = R.drawable.baseline_delete_24), // Material Design delete icon
                        contentDescription = "Delete",
                        modifier = Modifier.size(20.dp) // Icon size
                    )
                }
            }
        }
    }
}
