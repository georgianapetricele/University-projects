import { Redirect } from "expo-router";
import { Text, View } from "react-native";
import { Tabs } from "expo-router";
import { GestureHandlerRootView } from "react-native-gesture-handler";

export default function Index() {
  return (
      <Redirect href={"/home"} />
  );
}
