import React, { createContext, useState, useContext } from "react";

const RecipeContext = createContext();

export const useRecipeContext = () => useContext(RecipeContext);

export const RecipeProvider = ({ children }) => {
  const [recipes, setRecipes] = useState([
    {
      id: 1,
      name: "Spaghetti Bolognese",
      ingredients: "Pasta, Ground Beef, Tomato Sauce, Garlic, Olive Oil",
      preparationSteps: "Boil the pasta. Cook the beef. Combine with sauce.",
      preparationTime: 30,
    },
    {
      id: 2,
      name: "Chicken Curry",
      ingredients: "Chicken, Curry Powder, Coconut Milk, Garlic, Ginger",
      preparationSteps: "Fry chicken, add spices, simmer with coconut milk.",
      preparationTime: 45,
    },
    {
      id: 2,
      name: "Salad",
      ingredients: "Lettuce, Tomato",
      preparationSteps: "1. Chop vegetables.\n2. Mix together.\n3. Serve.",
      preparationTime: 10,
    },
  ]);

  const addRecipe = (recipe) => {
    setRecipes([...recipes, recipe]);
  };

  const editRecipe = (updatedRecipe) => {
    setRecipes(
      recipes.map((recipe) =>
        recipe.id === updatedRecipe.id ? updatedRecipe : recipe
      )
    );
  };

  const deleteRecipe = (id) => {
    setRecipes((prevRecipes) =>
      prevRecipes.filter((recipe) => recipe.id !== id)
    );
  };

  return (
    <RecipeContext.Provider
      value={{ recipes, addRecipe, editRecipe, deleteRecipe }}
    >
      {children}
    </RecipeContext.Provider>
  );
};
