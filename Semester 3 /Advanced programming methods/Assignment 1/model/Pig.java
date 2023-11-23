package model;

public class Pig implements IAnimal {
    private Integer weight;
    private String name;
    public Pig(String name,Integer weight) {
        this.name=name;
        this.weight=weight;
    }

    public String toString(){
        return "Pig " + this.name+ ": "+this.weight;
    }

    public Integer getWeight(){
        return this.weight;
    }

    public String getName(){
        return this.name;
    }

    public void setWeight(Integer weight){
        this.weight = weight;
    }

    public void setName(String name){
        this.name = name;
    }

}

