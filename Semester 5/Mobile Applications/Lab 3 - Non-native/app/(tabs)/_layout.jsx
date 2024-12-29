import { View, Text } from "react-native";
import React from "react";
import { Tabs } from "expo-router";
import Ionicons from "@expo/vector-icons/Ionicons";
import { Colors } from "./../../constants/Colors";

export default function TabLayout() {
  return (
    <Tabs
      screenOptions={{
        tabBarActiveTintColor: Colors.primary,
      }}
    >
      <Tabs.Screen redirect name="index" />
      <Tabs.Screen
        name="home"
        options={{
          tabBarIcon: ({ color }) => (
            <Ionicons name="home-outline" size={24} color="black" />
          ),
          headerShown: true,
          headerTitle: "My Recipes",
          headerTitleAlign: "center",
          headerTitleStyle: {
            color: "#a56600",
            fontSize: 20,
            fontWeight: "bold",
          },
        }}
      />
    </Tabs>
  );
}
