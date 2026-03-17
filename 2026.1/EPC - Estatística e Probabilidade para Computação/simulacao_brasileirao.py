import random

resultados = ["V", "E", "D"]
pesos = [0.43, 0.22, 0.35]

simulacao = random.choices(resultados, pesos, k=200)

print("Vitórias:", simulacao.count("V"))
print("Empates:", simulacao.count("E"))
print("Derrotas:", simulacao.count("D"))
