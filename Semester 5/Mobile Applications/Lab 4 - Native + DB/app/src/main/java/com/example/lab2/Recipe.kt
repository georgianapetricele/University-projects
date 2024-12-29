package com.example.lab2

import androidx.room.Entity
import androidx.room.PrimaryKey

@Entity
data class Recipe(
    @PrimaryKey(autoGenerate = true)
    var id: Int=0,
    var name: String,
    var ingredients: String,
    var preparationSteps: String,
    var preparationTime: Int,
)
