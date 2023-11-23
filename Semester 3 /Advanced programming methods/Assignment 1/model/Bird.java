package model;

public class Bird implements IAnimal {

    private Integer weight;
    private String name;
    public Bird(String name,Integer weight){
        this.weight=weight;
        this.name=name;
    }

    public String toString(){
        return "Bird " + this.name+": "+this.weight;
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

