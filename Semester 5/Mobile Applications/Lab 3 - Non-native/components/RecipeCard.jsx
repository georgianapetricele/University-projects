import React from "react";
import { View, Text, TouchableOpacity, StyleSheet } from "react-native";

export default function RecipeCard({ recipe, onEdit, onDelete }) {
  return (
    <View style={styles.card}>
      <Text style={styles.title}>{recipe.name}</Text>
      <Text style={styles.text}>Ingredients: {recipe.ingredients}</Text>
      <Text style={styles.text}>
        Preparation Steps: {recipe.preparationSteps}
      </Text>
      <Text style={styles.text}>
        Preparation Time: {recipe.preparationTime} minutes
      </Text>
      <View style={styles.actions}>
        <TouchableOpacity onPress={onEdit} style={styles.editButton}>
          <Text style={styles.buttonText}>Edit</Text>
        </TouchableOpacity>
        <TouchableOpacity onPress={onDelete} style={styles.deleteButton}>
          <Text style={styles.buttonText}>Delete</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  card: {
    backgroundColor: "#f8f9fa",
    borderRadius: 8,
    padding: 15,
    marginVertical: 10,
    marginHorizontal: 20,
    shadowColor: "#000",
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.1,
    shadowRadius: 5,
  },
  title: {
    fontSize: 18,
    fontWeight: "bold",
    marginBottom: 8,
  },
  text: {
    fontSize: 14,
    color: "#555",
    marginBottom: 5,
  },
  actions: {
    flexDirection: "row",
    justifyContent: "space-between",
    marginTop: 10,
  },
  editButton: {
    backgroundColor: "#a56600",
    padding: 8,
    borderRadius: 5,
  },
  deleteButton: {
    backgroundColor: "#dc3545",
    padding: 8,
    borderRadius: 5,
  },
  buttonText: {
    color: "#fff",
    fontSize: 14,
    textAlign: "center",
  },
});
