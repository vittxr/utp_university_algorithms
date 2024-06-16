from abc import ABC, abstractmethod


class PlacaDeVideo(ABC):
    def __init__(self, marca, modelo, qtd_memoria, clock):
        self.marca = marca
        self.modelo = modelo
        self.qtd_memoria = qtd_memoria
        self.clock = clock

    @abstractmethod
    def informacao(self):
        pass

    @abstractmethod
    def calcular_performance(self):
        pass


# OBS: Todos os métodos da PlacaDeVideo devem ser declarados OBRIGATORIAMENTE nas classes filhas (se não forem, o código retornará erro)
# Ex 2:
class PlacaDeJogos(PlacaDeVideo):
    def __init__(self, marca, modelo, qtd_memoria, clock, suporte_ray_tracing):
        super().__init__(marca, modelo, qtd_memoria, clock)
        self.suporte_ray_tracing = suporte_ray_tracing

    def informacao(self):
        return (
            f"Marca: {self.marca}, Modelo: {self.modelo}, Quantidade de Memória: {self.qtd_memoria}GB, "
            f"Clock: {self.clock}MHz, Suporte Ray Tracing: {self.suporte_ray_tracing}"
        )

    def calcular_performance(self):
        return self.qtd_memoria * self.clock


# Ex 3:
class PlacaProfissional(PlacaDeVideo):
    def __init__(self, marca, modelo, qtd_memoria, clock, certificacoes_software):
        super().__init__(marca, modelo, qtd_memoria, clock)
        self.certificacoes_software = certificacoes_software

    def informacao(self):
        certificacoes = ", ".join(self.certificacoes_software)
        return (
            f"Marca: {self.marca}, Modelo: {self.modelo}, Quantidade de Memória: {self.qtd_memoria}GB, "
            f"Clock: {self.clock}MHz, Certificações de Software: {certificacoes}"
        )

    def calcular_performance(self):
        return self.qtd_memoria * self.clock


# Ex 4:
class ColecaoPlacaDeVideo:
    def __init__(self):
        self.lista_placas = []

    def adicionar_placa(self, placa):
        self.lista_placas.append(placa)

    def mostrar_modelo_melhor_performance(self):
        if not self.lista_placas:
            return "Nenhuma placa na coleção."

        # max é uma função que recebe um "iterável" (algo que seja "loopável": listas, vetores, matrizes, etc)
        # melhor_placa = max(
        #     self.lista_placas, key=lambda placa: placa.calcular_performance()
        # )

        # esse código pode ser feito assim também (é muito menos enxuto, mas é mais fácil de entender):
        melhor_placa = self.lista_placas[0]
        for placa in self.lista_placas:
            if melhor_placa.calcular_performance() <= placa.calcular_performance():
                melhor_placa = placa

        return melhor_placa.modelo


# Ex 5:
if __name__ == "__main__":
    placa1 = PlacaDeJogos("NVIDIA", "RTX 3080", 10, 1440, "sim")
    placa2 = PlacaDeJogos("AMD", "RX 6800", 16, 1815, "não")
    placa3 = PlacaProfissional(
        "NVIDIA", "Quadro RTX 6000", 24, 1620, ["AutoCAD", "Maya", "Blender"]
    )
    placa4 = PlacaProfissional(
        "AMD", "Radeon Pro W5700", 8, 1935, ["SolidWorks", "Revit", "3ds Max"]
    )

    colecao = ColecaoPlacaDeVideo()
    colecao.adicionar_placa(placa1)
    colecao.adicionar_placa(placa2)
    colecao.adicionar_placa(placa3)
    colecao.adicionar_placa(placa4)

    for placa in colecao.lista_placas:
        print(placa.informacao())
        print(f"Performance: {placa.calcular_performance()}")
        print()

    print(
        f"Modelo com melhor performance: {colecao.mostrar_modelo_melhor_performance()}"
    )
