import React, { useState, useEffect } from "react";
import {
  View,
  TextInput,
  Button,
  Text,
  StyleSheet,
  Touchable,
  TouchableOpacity,
} from "react-native";
import { useLocalSearchParams } from "expo-router";
import { useRecipeContext } from "../context";
import { useRouter } from "expo-router";
import { useNavigation } from "@react-navigation/native";

export default function EditRecipe() {
  const { id } = useLocalSearchParams();
  const { recipes, editRecipe } = useRecipeContext();
  const [name, setName] = useState("");
  const [ingredients, setIngredients] = useState("");
  const [preparationSteps, setPreparationSteps] = useState("");
  const [preparationTime, setPreparationTime] = useState("");
  const [error, setError] = useState(null);
  const router = useRouter();

  const navigation = useNavigation();

  useEffect(() => {
    navigation.setOptions({
      headerShown: false,
    });
  }, [navigation]);

  useEffect(() => {
    if (id) {
      const recipe = recipes.find((r) => r.id.toString() === id);
      if (recipe) {
        setName(recipe.name);
        setIngredients(recipe.ingredients);
        setPreparationSteps(recipe.preparationSteps);
        setPreparationTime(recipe.preparationTime.toString());
      }
    }
  }, [id, recipes]);

  const handleEdit = () => {
    if (!name.trim() || !ingredients.trim() || !preparationSteps.trim()) {
      setError("All fields must be filled.");
      return;
    }

    const time = parseInt(preparationTime);
    if (isNaN(time) || time <= 0) {
      setError("Preparation time must be a valid positive number.");
      return;
    }

    setError(null);

    editRecipe({
      id: parseInt(id),
      name,
      ingredients,
      preparationSteps,
      preparationTime: time,
    });
    router.push("/home");
  };

  return (
    <View style={styles.container}>
      <Text style={styles.heading}>Edit the Recipe</Text>
      <View style={styles.inputGroup}>
        <Text style={styles.label}>Recipe Name</Text>
        <TextInput
          placeholder="Recipe Name"
          value={name}
          onChangeText={setName}
          style={styles.input}
        />
      </View>

      <View style={styles.inputGroup}>
        <Text style={styles.label}>Ingredients</Text>
        <TextInput
          placeholder="Ingredients"
          value={ingredients}
          onChangeText={setIngredients}
          style={styles.input}
        />
      </View>

      <View style={styles.inputGroup}>
        <Text style={styles.label}>Preparation Steps</Text>
        <TextInput
          placeholder="Preparation Steps"
          value={preparationSteps}
          onChangeText={setPreparationSteps}
          style={styles.input}
        />
      </View>

      <View style={styles.inputGroup}>
        <Text style={styles.label}>Preparation Time (minutes)</Text>
        <TextInput
          placeholder="Preparation Time (minutes)"
          value={preparationTime}
          keyboardType="numeric"
          onChangeText={setPreparationTime}
          style={styles.input}
        />
      </View>

      {error && <Text style={styles.error}>{error}</Text>}

      {/* <Button
        style={styles.editButton}
        title="Update Recipe"
        onPress={handleEdit}
        color="#a56600"
      /> */}
      <TouchableOpacity onPress={handleEdit} style={styles.editButton}>
        <Text style={{ color: "#fff" }}>Update Recipe</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    padding: 20,
    paddingTop: 100,
    flex: 1,
    backgroundColor: "#fff9eb",
  },
  heading: {
    fontSize: 24,
    fontWeight: "bold",
    color: "#a56600",
    marginBottom: 20,
    textAlign: "center",
  },
  inputGroup: {
    marginBottom: 15,
  },
  label: {
    fontSize: 16,
    fontWeight: "bold",
    marginBottom: 5,
    color: "#333",
  },
  input: {
    borderWidth: 1,
    borderColor: "#ccc",
    padding: 10,
    marginBottom: 10,
    borderRadius: 5,
    backgroundColor: "#fff",
  },
  error: {
    color: "red",
    marginBottom: 10,
    fontWeight: "bold",
  },
  editButton: {
    backgroundColor: "#a56600",
    color: "#fff",
    padding: 8,
    borderRadius: 5,
    alignItems: "center",
  },
});
