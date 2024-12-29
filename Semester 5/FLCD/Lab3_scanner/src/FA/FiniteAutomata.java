package FA;

import domain.Pair;

import java.io.*;
import java.nio.file.Files;
import java.util.*;
public class FiniteAutomata {
    List<String> states;
    List<String> alphabet;
    String initialState;
    List<String> finalStates;
    List<Transition> transitions;

    private HashMap<Pair<String, String>, List<String>> T = new HashMap<>();

    String filename;



    public FiniteAutomata(String filename) {
        this.states = new ArrayList<>();
        this.alphabet = new ArrayList<>();
        this.finalStates = new ArrayList<>();
        this.transitions = new ArrayList<>();
        this.initialState = "";
        this.filename = filename;
        try{
            readFromFile();
        } catch (Exception e) {
            System.out.println("Error when initializingFA");
        }
    }


    public void readFromFile() throws IOException {
        File filename = new File(this.filename);
        BufferedReader br = Files.newBufferedReader(filename.toPath());
        String line;
        while ((line = br.readLine()) != null) {
            String[] parts = line.split(":");

            String key = parts[0];
            switch(key){
                case"states":
                    String[] statesString = parts[1].trim().split(",");
                    states.addAll(Arrays.asList(statesString));
                    break;
                case"alphabet":
                    String[] alphabetString = parts[1].trim().split(",");
                    alphabet.addAll(Arrays.asList(alphabetString));
                    break;
                case"initial state":
                    initialState = parts[1].trim();
                    break;
                case"final states":
                    String[] finalStatesString = parts[1].trim().split(",");
                    finalStates.addAll(Arrays.asList(finalStatesString));
                    break;
                case"transitions":
                    String[] tuples = parts[1].trim().split(",");
                    for(var tuple: tuples){
                        Transition createTuple = new Transition();
                        String[] tupleElements = tuple.trim().split(" ");
                        createTuple.setFrom(tupleElements[0]);
                        createTuple.setTo(tupleElements[1]);
                        createTuple.setLabel(tupleElements[2]);

                        transitions.add(createTuple);

                        List<String> stringList;

                        Pair <String, String> pair = new Pair<>(tupleElements[0], tupleElements[1]);
                        try {
                            if (!T.get(pair).isEmpty()) {
                                stringList = new ArrayList<>(T.get(pair));
                                stringList.add(tupleElements[2]);
                                T.put(pair, stringList);
                            }
                        } catch (NullPointerException e) {
                            T.put(pair, Collections.singletonList(tupleElements[2]));
                        }
                    }

                    break;
            }


        }
    }

    private void printListOfString(String listname, List<String> list) {
        System.out.print(listname + " = {");
        for (int i = 0; i < list.size(); i++) {
            if (i != list.size() - 1) {
                System.out.print(list.get(i) + ", ");
            } else {
                System.out.print(list.get(i));
            }
        }
        System.out.println("}");
    }

    public void printStates() {
        printListOfString("states", states);
    }

    public void printAlphabet() {
        printListOfString("alphabet", alphabet);
    }

    public void printOutputStates() {
        printListOfString("out_states", finalStates);
    }

    public void printInitialState() {
        System.out.println("initial_state = " + initialState);
    }

    public void printTransitions() {
        System.out.print("transitions = {");
        for (int i = 0; i < transitions.size(); i++) {
            if (i != transitions.size() - 1) {
                System.out.print("(" + transitions.get(i).getFrom() + ", " + transitions.get(i).getTo() + ", " + transitions.get(i).getLabel() + "); ");
            } else {
                System.out.print("(" + transitions.get(i).getFrom() + ", " + transitions.get(i).getTo() + ", " + transitions.get(i).getLabel() + ")");
            }
        }
        System.out.println("}");
    }

    public boolean isDFA() {
        for (Pair<String, String> p : T.keySet()) {
            if (T.get(p).size() > 1) {
                return false;
            }
        }
        return true;
    }

    public boolean checkAcceptedSequence(String word) {
        if(!isDFA())
            return false;
        List<String> wordAsList = List.of(word.split(""));
        var currentState = initialState;
        for (String c: wordAsList) {
            var found = false;
            for (Transition transition: transitions) {
                if (transition.getFrom().equals(currentState) && transition.getLabel().equals(c)) {
                    currentState = transition.getTo();
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return finalStates.contains(currentState);
    }

    public String getNextAccepted(String word) {
        var currentState = initialState;
        StringBuilder firstSymbol= new StringBuilder();
        boolean found = false;
        StringBuilder lastSymbol = new StringBuilder();
        StringBuilder acceptedWord = new StringBuilder();
        for (String c: word.split("")) {
            String newState = null;
            for (Transition transition: transitions) {
                if (transition.getFrom().equals(currentState) && transition.getLabel().equals(c)) {
                    newState = transition.getTo();
                    if(!found)
                    {
                        firstSymbol.append(c);
                        found = true;
                    }
                    acceptedWord.append(c);
                    break;
                }
                lastSymbol.append(c);
            }
            if (newState == null) {
                if (!finalStates.contains(currentState)) {
                    return null;
                } else {
                    return acceptedWord.toString();
                }
            }
            currentState = newState;

        }
        return acceptedWord.toString();
    }

}