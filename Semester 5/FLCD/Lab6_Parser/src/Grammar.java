//
//import java.io.BufferedReader;
//import java.io.FileReader;
//import java.io.IOException;
//import java.util.*;
//
//public class Grammar {
//    public List<String> nonTerminals;
//    public List<String> terminals;
//    public String startingSymbol;
//    public Map<ArrayList<String>, ArrayList<List<String>>> productionRules;
//
//    public Grammar() {
//        this.productionRules = new HashMap<>();
//    }
//
//    public void readGrammar(String fileName) throws Exception {
//        List <String> stringList;
//        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
//            String line;
//            nonTerminals = getStatesFromLine(br);
//            terminals = getStatesFromLine(br);
//            startingSymbol = getStatesFromLine(br).get(0);
//            br.readLine();
//            while ((line = br.readLine()) != null) {
//                //lineList o sa aiba tot timpul 2 elemente
//                //pe pozitia 0 key, pe pozitia 1 lista de valori
//                List<String> lineList = Arrays.asList(line.split("->"));
//                ArrayList<String> key = new ArrayList<>();
//                key.add(lineList.get(0).strip());
//                ArrayList<List<String>> value = new ArrayList<>();
//                String[] token = lineList.get(1).split("\\|");
//                for(var str:token){
//                    List<String> prod = Arrays.asList(str.strip().split(" "));
//                    value.add(prod);
//                }
//                productionRules.put(key, value);
//            }
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
////        productionRules.entrySet().forEach(entry -> {
////            System.out.println(entry.getKey() + " -> " + entry.getValue());
////        });
//    }
//
//    private List<String> getStatesFromLine(BufferedReader br) throws IOException {
//        String line = br.readLine();
//        List <String> list =  Arrays.asList(line.split(" "));
//        return list.subList(2, list.size());
//    }
//
//    public void checkCFG() throws Exception{
//        for(Map.Entry element : productionRules.entrySet()) {
//            List<String> key = (List<String>) element.getKey();
//            for (String str : key) {
//                if (!nonTerminals.contains(str)) {
//                    throw new Exception("Grammar is not CFG");
//                }
//            }
//        }
//    }
//
//    public void validate() throws Exception {
//        if (!nonTerminals.contains(startingSymbol)) {
//            throw new Exception("the starting symbol is not in the set of non terminals");
//        }
//
//        for(Map.Entry element : productionRules.entrySet()) {
//            List<String> key = (List<String>) element.getKey();
//            if(key.size() > 1) {
//                throw new Exception("One key has more than one element");
//            }
//
//            List<List<String>> value = (List<List<String>>) element.getValue();
//            for(List l : value) {
//                for(Object o: l) {
//                    String str = (String) o;
//                    for(var oneStr: str.split(" ")) {
//                        if (!nonTerminals.contains(oneStr) && !terminals.contains(oneStr) && !str.equals("E")) { // Check for Epsilon, alphabet
//                            throw new Exception(oneStr + " is not found in the set of non terminals or terminals");
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    public Map<List<String>, List<List<String>>> filterProductionsByNonTerminal(String nonTerminal) {
//        Map<List<String>, List<List<String>>> result = new HashMap<>();
//        for (Map.Entry element : productionRules.entrySet()) {
//            List<String> key = (List<String>) element.getKey();
//            if (key.contains(nonTerminal)) {
//                var value = (List<List<String>>) element.getValue();
//                result.put(key, value);
//            }
//        }
//        return result;
//    }
//
//
//}

import java.io.*;
import java.nio.file.*;
import java.util.*;

public class Grammar {
    private List<String> N;
    private List<String> E;
    private String S;
    private Map<String, List<List<String>>> P;

    public Grammar() {
        this.N = new ArrayList<>();
        this.E = new ArrayList<>();
        this.S = "";
        this.P = new HashMap<>();
    }

    public void rebuild() {
        this.N.clear();
        this.E.clear();
        this.S = "";
        this.P.clear();
    }

    private List<String> getStatesFromLine(BufferedReader br) throws IOException {
        String line = br.readLine();
        List <String> list =  Arrays.asList(line.split(" "));
        return list.subList(2, list.size());
    }

    public void readFromFile(String fileName) throws IOException {
        this.rebuild();
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            this.N = getStatesFromLine(br);
            this.E = getStatesFromLine(br);
            this.S = getStatesFromLine(br).get(0);
            br.readLine();

            while ((line = br.readLine()) != null && !line.contains(" -> ")) {}

            while (line != null) {
                if (line.contains(" -> ")) {
                    String[] parts = line.split(" -> ");
                    String source = parts[0].strip();
                    String[] productions = parts[1].split("\\|");
                    for (String production : productions) {
                        List<String> prodList = Arrays.asList(production.strip().split("\\s+"));
                        P.computeIfAbsent(source, k -> new ArrayList<>()).add(prodList);
                    }
                }
                line = br.readLine();
            }

        }
    }

    public boolean checkCFG() {
        boolean hasStartSymbol = P.containsKey(S);
        for (String key : P.keySet()) {
            if (!N.contains(key)) return false;
            for (List<String> production : P.get(key)) {
                for (String value : production) {
                    if (!N.contains(value) && !E.contains(value)) return false;
                }
            }
        }
        return hasStartSymbol;
    }

    public List<String> getNonTerminals() { return N; }
    public List<String> getTerminals() { return E; }
    public String getStartSymbol() { return S; }
    public Map<String, List<List<String>>> getProductions() { return P; }
    public List<List<String>> getProductionsForNonTerminal(String nt) {
        return P.getOrDefault(nt, new ArrayList<>());
    }

    @Override
    public String toString() {
        return "N = " + N + "\nE = " + E + "\nS = " + S + "\nP = " + P + "\n";
    }
}
