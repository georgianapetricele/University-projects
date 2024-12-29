package grammar;

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
