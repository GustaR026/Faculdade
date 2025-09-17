import random
from collections import deque

class Cache:

    def __init__(self, tamanho_cache_em_blocos, tamanho_bloco, tipo_mapeamento, n_vias=None, politica_substituicao='FIFO'):
        self.tamanho_cache = tamanho_cache_em_blocos
        self.tamanho_bloco = tamanho_bloco
        self.tipo_mapeamento = tipo_mapeamento.lower()
        self.politica_substituicao = politica_substituicao.upper()
        self.hits = 0
        self.misses = 0

        if self.tipo_mapeamento == 'direto':
            self.n_conjuntos = self.tamanho_cache
            self.vias_por_conjunto = 1
            self.cache = {i: [None, None] for i in range(self.n_conjuntos)}
        elif self.tipo_mapeamento == 'associativo':
            self.n_conjuntos = 1
            self.vias_por_conjunto = self.tamanho_cache
            self.cache = {0: {}}
        elif self.tipo_mapeamento == 'conjunto-associativo':
            if n_vias is None or self.tamanho_cache % n_vias != 0:
                raise ValueError("Para conjunto-associativo, informe 'n_vias' que divide 'tamanho_cache_em_blocos'.")
            self.n_conjuntos = self.tamanho_cache // n_vias
            self.vias_por_conjunto = n_vias
            self.cache = {i: {} for i in range(self.n_conjuntos)}
        else:
            raise ValueError("Tipo de mapeamento inválido. Use 'direto', 'associativo' ou 'conjunto-associativo'.")

        if self.politica_substituicao in ['FIFO', 'LRU']:
            self.substituicao_listas = {i: deque(maxlen=self.vias_por_conjunto) for i in range(self.n_conjuntos)}

    def _obter_indices(self, endereco):
        bloco_endereco = endereco // self.tamanho_bloco
        if self.tipo_mapeamento == 'direto' or self.tipo_mapeamento == 'conjunto-associativo':
            indice = bloco_endereco % self.n_conjuntos
            tag = bloco_endereco // self.n_conjuntos
        else:  # Associativo
            indice = 0
            tag = bloco_endereco
        return tag, indice

    def _substituir_bloco(self, conjunto_id, tag_a_inserir, dados_a_inserir):
        conjunto = self.cache[conjunto_id]

        if self.politica_substituicao == 'FIFO':
            tag_removida = self.substituicao_listas[conjunto_id].popleft()
        elif self.politica_substituicao == 'LRU':
            tag_removida = self.substituicao_listas[conjunto_id].popleft()
        elif self.politica_substituicao == 'RANDOM':
            tag_removida = random.choice(list(conjunto.keys()))
        else:
            raise ValueError("Política de substituição inválida.")

        del conjunto[tag_removida]

        if self.politica_substituicao in ['FIFO', 'LRU']:
            self.substituicao_listas[conjunto_id].append(tag_a_inserir)

        conjunto[tag_a_inserir] = dados_a_inserir

    def read(self, endereco):
        tag, conjunto_id = self._obter_indices(endereco)

        if self.tipo_mapeamento == 'direto':
            bloco_na_cache = self.cache[conjunto_id]
            if bloco_na_cache[0] == tag:
                self.hits += 1
                return True, bloco_na_cache[1]
            else:
                self.misses += 1
                dados = f"Dados do Endereço {endereco}"
                self.cache[conjunto_id] = [tag, dados]
                return False, dados

        else:
            conjunto = self.cache[conjunto_id]
            if tag in conjunto:
                self.hits += 1
                if self.politica_substituicao == 'LRU':
                    self.substituicao_listas[conjunto_id].remove(tag)
                    self.substituicao_listas[conjunto_id].append(tag)
                return True, conjunto[tag]
            else:
                self.misses += 1
                dados = f"Dados do Endereço {endereco}"
                if len(conjunto) >= self.vias_por_conjunto:
                    self._substituir_bloco(conjunto_id, tag, dados)
                else:
                    conjunto[tag] = dados
                    if self.politica_substituicao in ['FIFO', 'LRU']:
                        self.substituicao_listas[conjunto_id].append(tag)
                return False, dados

    def exibir_estatisticas(self):
        total_acessos = self.hits + self.misses
        if total_acessos == 0:
            print("Nenhum acesso à cache.")
            return

        hit_rate = (self.hits / total_acessos) * 100
        print("\n--- Estatísticas da Cache ---")
        print(f"Tipo de Mapeamento: {self.tipo_mapeamento.capitalize()}")
        if self.tipo_mapeamento != 'direto':
            print(f"Política de Substituição: {self.politica_substituicao}")
        print(f"Acessos totais: {total_acessos}")
        print(f"Hits: {self.hits}")
        print(f"Misses: {self.misses}")
        print(f"Taxa de Acerto (Hit Rate): {hit_rate:.2f}%")

if __name__ == "__main__":
    # Teste 1: Direto
    print("### Teste 1: Mapeamento Direto ###")
    cache_direta = Cache(tamanho_cache_em_blocos=8, tamanho_bloco=4, tipo_mapeamento='direto')
    acessos = [0, 4, 8, 12, 0, 4, 8, 12, 16, 20]
    print(acessos)
    for end in acessos:
        hit, _ = cache_direta.read(end)
        print(f"Acesso ao endereço {end}: {'HIT' if hit else 'MISS'}")
    cache_direta.exibir_estatisticas()

    print("\n" + "="*50 + "\n")

    # Teste 2: Conjunto-Associativo (2 vias, FIFO)
    print("### Teste 2: Conjunto-Associativo (2 vias, FIFO) ###")
    cache_conj_fifo = Cache(tamanho_cache_em_blocos=8, tamanho_bloco=4, tipo_mapeamento='conjunto-associativo', n_vias=2, politica_substituicao='FIFO')
    acessos = [0, 16, 0, 16, 32, 48, 0, 16]
    print(acessos)
    for end in acessos:
        hit, _ = cache_conj_fifo.read(end)
        print(f"Acesso ao endereço {end}: {'HIT' if hit else 'MISS'}")
    cache_conj_fifo.exibir_estatisticas()

    print("\n" + "="*50 + "\n")

    # Teste 3: Associativo com FIFO
    print("### Teste 3: Associativo com FIFO ###")
    cache_assoc_fifo = Cache(tamanho_cache_em_blocos=4, tamanho_bloco=4, tipo_mapeamento='associativo', politica_substituicao='FIFO')
    acessos = [0, 4, 0, 4, 8, 12, 0, 4]
    print(acessos)
    for end in acessos:
        hit, _ = cache_assoc_fifo.read(end)
        print(f"Acesso ao endereço {end}: {'HIT' if hit else 'MISS'}")
    cache_assoc_fifo.exibir_estatisticas()

    print("\n" + "="*50 + "\n")

    # Teste 4: Associativo com LRU
    print("### Teste 4: Associativo com LRU ###")
    cache_assoc_lru = Cache(tamanho_cache_em_blocos=4, tamanho_bloco=4, tipo_mapeamento='associativo', politica_substituicao='LRU')
    acessos = [0, 4, 8, 0, 4, 12, 0, 4]
    print(acessos)
    for end in acessos:
        hit, _ = cache_assoc_lru.read(end)
        print(f"Acesso ao endereço {end}: {'HIT' if hit else 'MISS'}")
    cache_assoc_lru.exibir_estatisticas()

    print("\n" + "="*50 + "\n")

    # Teste 5: Associativo com RANDOM
    print("### Teste 5: Associativo com RANDOM ###")
    cache_assoc_random = Cache(tamanho_cache_em_blocos=4, tamanho_bloco=4, tipo_mapeamento='associativo', politica_substituicao='RANDOM')
    acessos = [0, 4, 8, 0, 4, 12]
    print(acessos)
    for end in acessos:
         hit, _ = cache_assoc_random.read(end)
    print(f"Acesso ao endereço {end}: {'HIT' if hit else 'MISS'}")
cache_assoc_random.exibir_estatisticas()

print("### Teste 6: Conjunto-Associativo (2 vias, LRU) ###")
cache_conj_lru = Cache(
    tamanho_cache_em_blocos=8,
    tamanho_bloco=4,
    tipo_mapeamento='conjunto-associativo',
    n_vias=2,
    politica_substituicao='LRU'
)

acessos_conj_lru = [0, 16, 0, 16, 32, 48, 0, 16]
print(acessos_conj_lru)
for end in acessos_conj_lru:
    hit, _ = cache_conj_lru.read(end)
    print(f"Acesso ao endereço {end}: {'HIT' if hit else 'MISS'}")
cache_conj_lru.exibir_estatisticas()

print("### Teste 7: Conjunto-Associativo (2 vias, RANDOM) ###")
cache_conj_random = Cache(
    tamanho_cache_em_blocos=8,
    tamanho_bloco=4,
    tipo_mapeamento='conjunto-associativo',
    n_vias=2,
    politica_substituicao='RANDOM'
)

acessos_conj_random = [0, 16, 0, 16, 32, 48, 0, 16]
print(acessos_conj_random)
for end in acessos_conj_random:
    hit, _ = cache_conj_random.read(end)
    print(f"Acesso ao endereço {end}: {'HIT' if hit else 'MISS'}")
cache_conj_random.exibir_estatisticas()

