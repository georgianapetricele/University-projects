package DS;

public class Node {

    private Integer father;
    private Integer sibling;
    private String value;
    private Integer production;

    public Node(String value) {
        this.father = -1;
        this.sibling =-1;
        this.value = value;
        this.production = -1;
    }

    public Integer getFather() {
        return father;
    }

    public Integer getSibling() {
        return sibling;
    }

    public String getValue() {
        return value;
    }

    public Integer getProduction() {
        return production;
    }

    public void setFather(Integer father) {
        this.father = father;
    }

    public void setSibling(Integer sibling) {
        this.sibling = sibling;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public void setProduction(Integer production) {
        this.production = production;
    }

    public String toString() {
        return value + " " + father + " " + sibling + " " + production;
    }
}
