import React from "react";
import {
  View,
  Button,
  FlatList,
  StyleSheet,
  Alert,
  TouchableOpacity,
} from "react-native";
import { useRecipeContext } from "../context";
import { useRouter } from "expo-router";
import RecipeCard from "./../../components/RecipeCard";
import Ionicons from "@expo/vector-icons/Ionicons";

export default function Home() {
  const { recipes, deleteRecipe } = useRecipeContext();
  const router = useRouter();

  const handleDelete = (id) => {
    Alert.alert(
      "Delete Recipe",
      "Are you sure you want to delete this recipe?",
      [
        { text: "Cancel", style: "cancel" },
        {
          text: "Delete",
          style: "destructive",
          onPress: () => deleteRecipe(id),
        },
      ]
    );
  };

  return (
    <View style={styles.container}>
      <FlatList
        data={recipes}
        keyExtractor={(item) => item.id.toString()}
        renderItem={({ item }) => (
          <RecipeCard
            recipe={item}
            onEdit={() => router.push(`/editRecipe/${item.id}`)}
            onDelete={() => handleDelete(item.id)}
          />
        )}
      />
      <TouchableOpacity
        style={styles.addButton}
        onPress={() => router.push("/addRecipe")}
      >
        <Ionicons name="add-circle-outline" size={50} color="#a56600" />
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingVertical: 20,
    backgroundColor: "#fff9eb",
  },
  addButton: {
    alignItems: "center",
    alignSelf: "center",
  },
});
