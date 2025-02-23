package domain;

public class Pair<T1, T2>
{
    public T1 first;
    public T2 second;


    public Pair(T1 first, T2 second)
    {
        this.first = first;
        this.second = second;
    }

    public T1 getFirst(){
        return this.first;
    }

    public T2 getSecond(){
        return this.second;
    }


    @Override
    public String toString()
    {
        return first.toString() + " " + second.toString();
    }
}