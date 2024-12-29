package algorithms;


import model.Polynomial;
import model.PolynomialUtils;

public class SequentialKaratsuba {

    public static Polynomial multiply(Polynomial p1, Polynomial p2) throws InterruptedException {
        if (p1.getDegree() < 2 || p2.getDegree() < 2) {
            return SequentialClassic.multiply(p1,p2);
        }

        //split the polynomials in 2 parts
        int len = Math.max(p1.getDegree(), p2.getDegree()) / 2;
        //P(X) = P1(X)*X^n+P2(X)
        //Q(X) = Q1(X)*X^n+Q2(X) Q1(X) - high part
        Polynomial lowP1 = new Polynomial(p1.getCoefficients().subList(0, len)); // low part first coefficients
        Polynomial highP1 = new Polynomial(p1.getCoefficients().subList(len, p1.getCoefficients().size()));
        Polynomial lowP2 = new Polynomial(p2.getCoefficients().subList(0, len));
        Polynomial highP2 = new Polynomial(p2.getCoefficients().subList(len, p2.getCoefficients().size()));

        //(D0*E0)
        Polynomial z1 = multiply(lowP1, lowP2);
        //(E1 + E0) * (D0 + D1)
        Polynomial z2 = multiply(PolynomialUtils.add(lowP1, highP1), PolynomialUtils.add(lowP2, highP2));
        //(D1*E1)
        Polynomial z3 = multiply(highP1, highP2);

        //calculate the final result
        //( (E1*D1) * (x^n) + ((E1 + E0) * (D0 + D1) - (D1*E1) - (D0*E0)) * (x ^ n/2) + E0D0)
        Polynomial r1 = PolynomialUtils.addZeros(z3, 2 * len);
        Polynomial r2 = PolynomialUtils.addZeros(PolynomialUtils.subtract(PolynomialUtils.subtract(z2, z3), z1), len);
        Polynomial result = PolynomialUtils.add(PolynomialUtils.add(r1, r2), z1);
        return result;
    }
}