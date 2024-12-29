import React, { useState, useEffect } from "react";
import {
  View,
  TextInput,
  Text,
  StyleSheet,
  Button,
  TouchableOpacity,
} from "react-native";
import { useNavigation } from "@react-navigation/native";
import { useRecipeContext } from "./context";
import { useRouter } from "expo-router";

export default function AddRecipe() {
  const [name, setName] = useState("");
  const [ingredients, setIngredients] = useState("");
  const [preparationSteps, setPreparationSteps] = useState("");
  const [preparationTime, setPreparationTime] = useState("");
  const [error, setError] = useState(null);

  const { addRecipe } = useRecipeContext();
  const router = useRouter();

  const navigation = useNavigation();

  useEffect(() => {
    navigation.setOptions({
      headerShown: false,
    });
  }, [navigation]);

  const handleAdd = () => {
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

    addRecipe({
      id: Math.floor(Math.random() * 1000),
      name,
      ingredients,
      preparationSteps,
      preparationTime: time,
    });

    router.push("/home");
  };

  return (
    <View style={styles.container}>
      <Text style={styles.heading}>Add a new Recipe</Text>
      <View style={styles.inputGroup}>
        <Text style={styles.label}>Recipe Name</Text>
        <TextInput value={name} onChangeText={setName} style={styles.input} />
      </View>

      <View style={styles.inputGroup}>
        <Text style={styles.label}>Ingredients</Text>
        <TextInput
          value={ingredients}
          onChangeText={setIngredients}
          style={styles.input}
        />
      </View>

      <View style={styles.inputGroup}>
        <Text style={styles.label}>Preparation Steps</Text>
        <TextInput
          value={preparationSteps}
          onChangeText={setPreparationSteps}
          style={styles.input}
        />
      </View>

      <View style={styles.inputGroup}>
        <Text style={styles.label}>Preparation Time (minutes)</Text>
        <TextInput
          value={preparationTime}
          keyboardType="numeric"
          onChangeText={setPreparationTime}
          style={styles.input}
        />
      </View>

      {error && <Text style={styles.error}>{error}</Text>}

      <TouchableOpacity onPress={handleAdd} style={styles.addButton}>
        <Text style={{ color: "#fff" }}>Add Recipe</Text>
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
  addButton: {
    backgroundColor: "#a56600",
    padding: 10,
    borderRadius: 5,
    alignItems: "center",
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
    borderRadius: 5,
    backgroundColor: "#fff",
  },
  error: {
    color: "red",
    marginBottom: 10,
    fontWeight: "bold",
  },
});
