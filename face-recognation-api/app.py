# app.py
import flask
import pickle
import base64
import numpy as np
# ... outras bibliotecas necessárias (ex: OpenCV, scikit-image)

# 1. Carregar o modelo .pkl quando o app for iniciado
MODELO_CARREGADO = pickle.load(open('embeddings.pkl', 'rb'))

app = flask.Flask(__name__)

@app.route('/reconhecimento_facial', methods=['POST'])
def prever():
    # Recebe o JSON enviado pelo FlutterFlow
    data = flask.request.json
    
    # 2. Extrai e decodifica a imagem Base64
    imagem_base64 = data['imagem']
    
    # ... Lógica para decodificar e pré-processar a imagem para o seu modelo ...
    
    # 3. Faz a previsão com o modelo .pkl
    resultado_predicao = MODELO_CARREGADO.predict(imagem_processada)
    
    # 4. Retorna a resposta em JSON
    return flask.jsonify({
        'status': 'sucesso',
        'nome_encontrado': resultado_predicao[0] 
    })
