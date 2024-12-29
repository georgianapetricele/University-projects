

# Recipes App

# Short Description

"MyRecipes" is a mobile app that makes it easy for users to manage their recipes. With a simple and user-friendly interface, users can access all their saved recipes and view detailed information for each one. The app also allows users to add new recipes, update existing ones, and delete recipes they no longer need. Additionally, users can mark their favorite recipes and view them in a dedicated favorites list.

# Domain details
Recipe 
 - ID: A number that represents an unique identifier for each recipe entry
 - Name: A string which contains the name of the recipe 
 - Ingredients: A string containing the list of ingredients necessary to prepare the recipe
 - Preparation Steps: A string containing the steps necessary for the user to prepare the recipe.
 - Preparation Time: A number representing the time taken to prepare the recipe
 - IsFavourite: A boolean that indicates if the user added the recipes to his favourites list.

# CRUD Operations
 - Create: To add a new recipe, users can press the " + " button located in the menu at the bottom of every page. They will then be redirected to a new page where they can fill in the details for the new recipe: name, ingredients, preparation steps, and preparation time.
 - Read: Users can view the list of all existing recipes on the main page of the application and the list of favourites recipes on the favourites recipes screen.
 - Update: To update a recipe, users can select one from the recipe list on the main page, which will take them to the recipe details page where they can modify the name, ingredients, preparation steps, and preparation time of the selected recipe.
 - Delete: To remove a recipe, users can press the delete button located on each recipe's card. A pop-up will appear asking if they want to delete the recipe. If they press "Yes," the recipe will be deleted and they will be redirected to the main page. If they press "No," they will simply return to the main page.
   To add a recipe to the favourites list, users can can press the heart shaped button located on each recipe's card.

# Persistence Details
  - Local DB: All CRUD operations are persisted on a local database to ensure the app remains functions even if it goes offline.
  - Server: Create, Update, and Delete operations are also persisted on a server to back up user data and allow for data recovery and synchronization across devices. Read operations are typically not persisted on the server as they do not modify data.

# Offline Access Scenarios
When the application is offline the default screen will notice the user that is offline.
  - Create: When offline, the added recipe is stored in the local database. It will be synchronized with the server once the device is back online.
  - Read: Users can still view and search through their recipes list when offline, as this data is fetched from the local database.
  - Update: Updates made while offline are saved to the local database and will be synchronized with the server once connectivity is restored.
  - Delete: Recipes deleted while offline are removed from the local database and this change will be reflected on the server when the device is back online.

 ![Group 13 (4)](https://github.com/user-attachments/assets/32cc424a-fb96-4eb3-93c0-087d97c5b754)

    


