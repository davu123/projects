import os 

restaurantes = [{'nome':'Praça', 'categoria': 'Japonesa', 'ativo':False}, 
                {'nome:': 'Pizza suprema', 'categoria': 'Pizza', 'ativo':True},
                {'nome': 'Cantina', 'categoria': 'Italiana', 'ativo':False}]

def exibir_nome_do_programa():
      print("""Sabor Express
      
      """)

def exibir_opcoes():
      print('1. Cadastrar restaurante')
      print('2. Listar restaurante')
      print('3. Ativar restaurante')
      print('4. Sair\n')

def finalizar_app():
     exibir_subtitulo('Finalizando app')

def voltar_ao_main():
      input('\nDigite uma tecla para voltar ao menu principal')
      main()

def opcao_invalida():
      print('Opcão inválida\n')
      voltar_ao_main()

def exibir_subtitulo(texto):
      os.system('cls')
      linha = '*' * (len(texto))
      print(linha)
      print(texto)
      print(linha)
      print() 
      
def cadastrar_novo_restaurante():
      exibir_subtitulo('Cadastro de novos restaurantes')
      nome_restaurante = input('Digite um nome do restaurante que deseja cadastrar: ')
      categoria = input(f'Digite o nome da categoria do restaurante {nome_restaurante}: ')
      dados_do_restaurante = {'nome':nome_restaurante, 'categoria': categoria,'ativo':False}
      restaurantes.append(dados_do_restaurante)
      print(f'O restaurante {nome_restaurante} foi cadastrado com sucesso')
      voltar_ao_main()

def listar_restaurantes():
      exibir_subtitulo('Listando restaurantes')
      
      for restaurante in restaurantes:
            nome_restaurante = restaurante['nome']
            categoria = restaurante['categoria']
            ativo = 'ativado' if restaurante['ativo'] else 'desativado'
            print(f'- {nome_restaurante} | {categoria} | {ativo}')

      voltar_ao_main()  


def alternar_estado_do_restaurante():
      exibir_subtitulo('Alternando estado do restaurante')
      nome_restaurante = input('Digite o nome do restaurante que deseja alternar o estado: ')
      restaurante_encontrado = False 

      for restaurante in restaurantes:
            if nome_restaurante == restaurantes['nome']:
                  restaurante_encontrado = True
                  restaurante['ativo'] = not restaurante['ativo']
                  mensagem = f'O restaurante {nome_restaurante}' if restaurante['ativo'] else f'O restaurante {nome_restaurante} foi desativado com sucesso'
                  print(mensagem)
      if not restaurante_encontrado:
            print('O restaurante não foi encontrado')


      voltar_ao_main()


def escolher_opcao():
      try:
            opcao_escolhida = int(input('Escolha uma opção: '))
            #   opcao_escolhida = int(opcao_escolhida)
            if opcao_escolhida == 1:
                  cadastrar_novo_restaurante()
            elif opcao_escolhida == 2:
                  listar_restaurantes()
            elif opcao_escolhida == 3:
                  alternar_estado_do_restaurante()
            elif opcao_escolhida == 4:
                  finalizar_app()
            else:
                  opcao_invalida()
      except:
            opcao_invalida()


def main():
    os.system('cls')
    exibir_nome_do_programa()
    exibir_opcoes()
    escolher_opcao()
    
if __name__ == '__main__':
    main()

