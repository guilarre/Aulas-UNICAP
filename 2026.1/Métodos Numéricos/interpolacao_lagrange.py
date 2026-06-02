x=[0,1,2,3,4]
y=[-2,1,0,-5,1]

def Lagrange(i,t,x):
    '''Polinomios de Lagrange, t lista de pontos da tabela'''
    produto=1
    for l in range(len(t)):
        if (l!=i) :
            produto = produto*(x-t[l])/(t[i]-t[l])
    return produto

def g(t):
  soma = 0
  for i in range(len(x)):
    soma = soma + y[i]*Lagrange(i,x,t)
  return soma

print(g(0.5))
