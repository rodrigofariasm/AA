# coding: utf-8
print "Escreva seu nome"
usuario = raw_input()
print "Olá " +usuario + "! \nVocê quer saber onde estará no próximo verão? sim/não "
resposta = raw_input()
if resposta == "sim":
    cidades = ["Dubai","Santorini","Queimadas","Cuité"]
    print "Escolha um número de 1 a 4"
    numero = int(raw_input())
    for cidade in cidades:
        if cidades[numero-1] == cidade:
            print "Que sorte! Você passará o próximo verão em " +cidade+"!"
else:
    print "Vlw fera!"
