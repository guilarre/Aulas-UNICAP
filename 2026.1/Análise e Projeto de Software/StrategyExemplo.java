// Strategy interface
public interface MathStrategy {
    int executeInt(int a, int b);
}

// Concrete Strategies
public class ConcreteMathStrategyAdd implements MathStrategy {
    @Override
    public int executeInt(int a, int b) {
        return a + b;
    }
}

public class ConcreteMathStrategyMultiply implements MathStrategy {
    @Override
    public int executeInt(int a, int b) {
        return a * b;
    }
}

// Context
public class MathContext {
    private MathStrategy strategy;

    public MathContext() {
        this.strategy = null;
    }

    public void setStrategy(MathStrategy strategy) {
        this.strategy = strategy;
    }

    public int executeStrategy(int a, int b) {
        if (this.strategy == null) {
            throw new IllegalStateException("Nenhuma estratégia foi definida!");
        }
        return this.strategy.executeInt(a, b);
    }
}

public class Cliente {
    public static void main(String[] args) {
        MathContext context = new MathContext(); //instancia um objeto context

        int x = 10, y = 5;

        // quero somar
        context.setStrategy(new ConcreteMathStrategyAdd()); //instancia um ConcreteMathStrategyAdd que implementa do nosso Strategy
        int resultado = context.executeStrategy(x, y);
        System.out.println("Resultado da soma: " + resultado);
    }
}
