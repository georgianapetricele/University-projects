// app/_layout.js
import { Stack } from "expo-router";
import { RecipeProvider } from "./context";
import { GestureHandlerRootView } from "react-native-gesture-handler";

export default function RootLayout() {
  return (
    <GestureHandlerRootView style={{ flex: 1 }}>
      <RecipeProvider>
        <Stack>
          <Stack.Screen
            name="(tabs)"
            options={{
              headerShown: false,
            }}
          />
        </Stack>
      </RecipeProvider>
    </GestureHandlerRootView>
  );
}
