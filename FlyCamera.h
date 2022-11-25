const int Width = 800;
const int Heigth = 600;



class FlyCamera {
public:

	void MoverPraFrente(float quantidade) {
		this->Location += glm::normalize(Direction) * quantidade * Speed;
	}

	void MoverPraDireita(float quantidade) {
		//Calcula o produto vetorial
		glm::vec3 Right = glm::normalize(glm::cross(Direction, Up));

		this->Location += Right * quantidade * Speed;
	}

	void OlharPara(float quantidadeEixoYyaw, float quantidadeEixoXpitch) {
		// Aplicando a velocidade do movimento
		quantidadeEixoYyaw *= Sensitivity;
		quantidadeEixoXpitch *= Sensitivity;

		// Matriz identidade
		const glm::mat4 MatrizIdentidade = glm::identity<glm::mat4>();
		// Produto vetorial
		glm::vec3 Right = glm::normalize(glm::cross(Direction, Up));

		// Criando as matrizes de rotação
		glm::mat4 MatrizRotacaoExioY = glm::rotate(MatrizIdentidade,
			glm::radians(quantidadeEixoYyaw),
			Up);
		glm::mat4 MatrizRotacaoExioX = glm::rotate(MatrizIdentidade,
			glm::radians(quantidadeEixoXpitch),
			Right);

		// Plicando nos vetores de direção
		this->Up = MatrizRotacaoExioX * glm::vec4{ this->Up , 0.0f };
		this->Direction = MatrizRotacaoExioY * MatrizRotacaoExioX * glm::vec4{ this->Direction , 0.0f };
	}

	glm::mat4 GetViewProjection() const {

		glm::mat4 View = glm::lookAt(Location, Location + Direction, Up);
		glm::mat4 Projection = glm::perspective(FieldOfView, AspectRatio, Near, Far);
		return Projection * View;
	}

	//Parametros de Interatividade, define a velocidade do movimento
	float Speed = 1;
	float Sensitivity = 0.1f;

	//Parametros da Matriz de view
	glm::vec3 Location{ 0.0f, 0.0f, 5.0f };
	glm::vec3 Direction{ 0.0f, 0.0f, -1.0f };
	glm::vec3 Up{ 0.0f, 1.0f, 0.0f };

	//Parâmetros da Matriz Projection
	float FieldOfView = glm::radians(45.0f);
	float AspectRatio = Width / Heigth;
	float Near = 0.01f;
	float Far = 1000.0f;
};