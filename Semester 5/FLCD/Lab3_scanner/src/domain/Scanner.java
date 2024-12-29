package domain;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.regex.Pattern;

public class Scanner {

    private String program;
    private SymbolTable<String> symbolTable;
    private ArrayList<Pair<String,Pair<Integer,Integer>>> pif;

    private List<String> reservedWords;
    private List<String> tokens;

    private int currentIndex;
    private int currentLine;

    public Scanner(String tokenFile){
        this.symbolTable = new SymbolTable<>(30);
        this.pif = new ArrayList<>();
        this.tokens=new ArrayList<>();
        this.reservedWords=new ArrayList<>();
        this.currentIndex=0;
        this.currentLine=1;

        readTokens(tokenFile);
    }


    private void readTokens(String tokenFile){
        tokens = new ArrayList<>();
        String[] words={"int","char","string","array","read","print","if","else","while","for"};

        try (BufferedReader br = new BufferedReader(new FileReader(tokenFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                tokens.add(line.strip());
                if(Arrays.asList(words).contains(line.strip()))
                {
                    reservedWords.add(line.strip());
                }
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void skipSpaces() {
        while (currentIndex < program.length() && Character.isWhitespace(program.charAt(currentIndex))) {
            if (program.charAt(currentIndex) == '\n') {
                currentLine++;
            }
            currentIndex++;
        }
    }

    private boolean processIdentifier() {
        var regexForIdentifier = Pattern.compile("^([a-zA-Z_][a-zA-Z0-9_]*)");
        String substring = program.substring(currentIndex);
        var matcher = regexForIdentifier.matcher(substring);
        if (!matcher.find()) {
            return false;
        }
        var identifier = matcher.group(1);
        if(reservedWords.contains(identifier))
            return false;

        currentIndex += identifier.length();
        Pair<Integer, Integer> position;

        try {
            symbolTable.addSymbol(identifier);
            position = symbolTable.getPositionForSymbol(identifier);

        } catch (Exception e) {
            position = symbolTable.getPositionForSymbol(identifier);
        }

        pif.add(new Pair<>("id", position));
        return true;
    }

    private boolean processIntConstant(){
        var regexForIntConstant = Pattern.compile("^([+-]?[1-9][0-9]*|0)(?![a-zA-Z_])");
        var matcher = regexForIntConstant.matcher(program.substring(currentIndex));
        if (!matcher.find()) {
            return false;
        }

        String intConstant = matcher.group(1);
        currentIndex += intConstant.length();
        Pair<Integer, Integer> position;
        try {
            symbolTable.addSymbol(intConstant);
            position = symbolTable.getPositionForSymbol(intConstant);
        } catch (Exception e) {
            position = symbolTable.getPositionForSymbol(intConstant);
        }
        pif.add(new Pair<>("const", position));
        return true;
    }

    private boolean processStringConstant() throws Exception {
        var regexForStringConstant = Pattern.compile("^\"[a-zA-z0-9_ ]*\"");
        var matcher = regexForStringConstant.matcher(program.substring(currentIndex));
        if (!matcher.find()) {
            if (Pattern.compile("^\"[^\"]").matcher(program.substring(currentIndex)).find()) {
                throw new Exception("Missing closing \" at line " + currentLine);
            }
            return false;
        }
        var stringConstant = matcher.group(0);
        currentIndex += stringConstant.length();
        Pair<Integer, Integer> position;
        try {
            symbolTable.addSymbol(stringConstant);
            position = symbolTable.getPositionForSymbol(stringConstant);
        } catch (Exception e) {
            position = symbolTable.getPositionForSymbol(stringConstant);
        }
        pif.add(new Pair<>("const", position));
        return true;
    }

    private boolean processCharConstant() throws Exception {
        var regexForCharConstant = Pattern.compile("^'[a-zA-Z0-9_ ]'");
        var matcher = regexForCharConstant.matcher(program.substring(currentIndex));

        if (!matcher.find()) {
            if(Pattern.compile("^'[^']+'").matcher(program.substring(currentIndex)).find()) {
                throw new Exception("Invalid character constant at line " + currentLine);
            }
            if (Pattern.compile("^'[^']").matcher(program.substring(currentIndex)).find()) {
                throw new Exception("Missing closing ' at line " + currentLine);
            }

            return false;
        }
        var charConstant = matcher.group(0);
        currentIndex += charConstant.length();

        Pair<Integer, Integer> position;

        try {
            symbolTable.addSymbol(charConstant);
            position = symbolTable.getPositionForSymbol(charConstant);
        } catch (Exception e) {
            position = symbolTable.getPositionForSymbol(charConstant);
        }

        pif.add(new Pair<>("const", position));

        return true;
    }


    private boolean processFromTokenList() {
        String possibleToken = program.substring(currentIndex).split(" ")[0];
        for (var reservedToken: reservedWords) {
            if (possibleToken.startsWith(reservedToken)) {
                var regex = "^[a-zA-Z0-9_]*" + reservedToken + "[a-zA-Z0-9_]+";
                if (Pattern.compile(regex).matcher(possibleToken).find()) {
                    return false;
                }
                currentIndex += reservedToken.length();
                pif.add(new Pair<>(reservedToken, new Pair<>(-1, -1)));
                return true;
            }
        }
        for (var token : tokens) {
            if (Objects.equals(token, possibleToken)) {
                currentIndex += token.length();
                pif.add(new Pair<>(token, new Pair<>(-1, -1)));
                return true;
            }
            else if (possibleToken.startsWith(token)) {
                currentIndex += token.length();
                pif.add(new Pair<>(token, new Pair<>(-1, -1)));
                return true;
            }
        }
        return false;
    }

    private boolean processReservedWord(){
        String RESERVED_WORDS_REGEX = "^\\b(int|char|string|array|read|print|if|else|while|for)\\b";
        var regexReservedWord = Pattern.compile(RESERVED_WORDS_REGEX);
        var matcher = regexReservedWord.matcher((program.substring(currentIndex)));

        if (!matcher.find()) {
            return false;
        }

        String result = matcher.group(0);
        currentIndex += result.length();
        return true;
    }

    private boolean processOperator() {
        String OPERATORS_REGEX = "^(==|!=|<=|>=|&&|\\|\\||\\+|-|\\*|/|%|=|<|>)";
        var regexOperator = Pattern.compile(OPERATORS_REGEX);
        var matcher = regexOperator.matcher(program.substring(currentIndex));

        if (!matcher.find()) {
            return false;
        }

        String matchedOperator = matcher.group(0);
        currentIndex += matchedOperator.length();
        return true;
    }

    private boolean processSeparator(){
        String SEPARATORS_REGEX = "^([;,{}()\\[\\]])";
        var regexSeparator = Pattern.compile(SEPARATORS_REGEX);
        var matcher = regexSeparator.matcher(program.substring(currentIndex));

        if (!matcher.find()) {
            return false;
        }

        String matchedPunctuation = matcher.group(0);
        currentIndex += matchedPunctuation.length();
        return true;
    }

    private void processElement(int index) throws Exception{
        skipSpaces();
        if (index == program.length()) {
            return;
        }
        if (processIdentifier()) {
            return;
        }
        if(processIntConstant()){
            return;
        }
        if (processStringConstant()) {
            return;
        }
        if (processCharConstant()) {
            return;
        }

        if(processFromTokenList()){
            return;
        }
//        if (processReservedWord()) {
//            return;
//        }
//        if (processOperator()) {
//            return;
//        }
//        if(processSeparator()){
//            return;
//        }

        throw new Exception("Lexical error: invalid token at line " + currentLine + ", index " + index);
    }

    private void writeToFiles(String programFileName) throws IOException {
        FileWriter fileWriter = new FileWriter("PIF" + programFileName.replace(".txt", ".out"));
        for (var pair : pif) {
            fileWriter.write(pair.getFirst() + " -> (" + pair.getSecond().getFirst() + ", " + pair.getSecond().getSecond() + ")\n");
        }
        fileWriter.close();
        fileWriter = new FileWriter("ST" + programFileName.replace(".txt", ".out"));
        fileWriter.write(symbolTable.toString());
        fileWriter.close();

        System.out.println("Lexically correct");
    }

    public void scan(String programFileName) throws IOException {
        boolean correct = true;
        try {
            Path file = Path.of("src/input/" + programFileName);
            setProgram(Files.readString(file));
            pif = new ArrayList<>();
            symbolTable = new SymbolTable<>(30);
            currentIndex=0;
            currentLine=1;

            while (currentIndex < program.length()) {
                processElement(currentIndex);
            }
            writeToFiles(programFileName);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private void setProgram(String filePath) {
        this.program = filePath;
    }


}
