

//Estrutura de um vertice
struct Vertice {
	glm::vec3 Posicao;
	glm::vec3 Cor;
	glm::vec2 UV;
};

GLuint Cube() {
	//Definição dos verticies
	std::array<Vertice, 24> Cube = {
		//frente
		//0
		Vertice{
			glm::vec3{	-1.0f,	-1.0f,	1.0f},
			glm::vec3{	1.0f,	0.0f,	0.0f},
			glm::vec2{	0.0f,	0.0f}
		},
		//1
		Vertice{
			glm::vec3{	1.0f,	-1.0f,	1.0f},
			glm::vec3{	0.0f,	1.0f,	0.0f},
			glm::vec2{	1.0f,	0.0f}
		},
		//2
		Vertice{
			glm::vec3{	1.0f,  1.0f,	1.0f},
			glm::vec3{	1.0f,	0.0f,	0.0f},
			glm::vec2{	1.0f,	1.0f	}
		},
		//3
		Vertice{
			glm::vec3{	-1.0f,  1.0f,	1.0f},
			glm::vec3{	0.0f,	0.0f,	1.0f},
			glm::vec2{	0.0f,	1.0f	}
		},

		//lado esquerdo
		//4
		Vertice{
				glm::vec3{	-1.0f,	1.0f,	-1.0f},
				glm::vec3{	0.0f,	1.0f,	0.0f},
				glm::vec2{	1.0f,	0.0f}
		},
		//5
		Vertice{
			glm::vec3{	-1.0f,	-1.0f,	-1.0f},
			glm::vec3{	1.0f,	0.0f,	0.0f},
			glm::vec2{	0.0f,	0.0f}
		},
		//6
		Vertice{
				glm::vec3{	-1.0f,  -1.0f,	1.0f},
				glm::vec3{	0.0f,	0.0f,	1.0f},
				glm::vec2{	0.0f,	1.0f	}
		},
		//7
		Vertice{
				glm::vec3{	-1.0f,  1.0f,	1.0f},
				glm::vec3{	1.0f,	0.0f,	0.0f},
				glm::vec2{	1.0f,	1.0f	}
		},
		
		


		//lado direito
		//8
		Vertice{
				glm::vec3{	1.0f,  -1.0f,	1.0f},
				glm::vec3{	1.0f,	0.0f,	0.0f},
				glm::vec2{	1.0f,	1.0f	}
		},
		//9
		Vertice{
				glm::vec3{	1.0f,	-1.0f,	-1.0f},
				glm::vec3{	0.0f,	1.0f,	0.0f},
				glm::vec2{	1.0f,	0.0f}
		},
		//10
		Vertice{
			glm::vec3{	1.0f,	1.0f,	-1.0f},
			glm::vec3{	1.0f,	0.0f,	0.0f},
			glm::vec2{	0.0f,	0.0f}
		},
		//11
		Vertice{
				glm::vec3{	1.0f,  1.0f,	1.0f},
				glm::vec3{	0.0f,	0.0f,	1.0f},
				glm::vec2{	0.0f,	1.0f	}
		},
		
		//costas
		//12
		Vertice{
			glm::vec3{	-1.0f,	-1.0f,	-1.0f},
			glm::vec3{	1.0f,	0.0f,	-1.0f},
			glm::vec2{	0.0f,	0.0f}
		},
		//15
		Vertice{
			glm::vec3{	-1.0f,  1.0f,	-1.0f},
			glm::vec3{	0.0f,	0.0f,	1.0f},
			glm::vec2{	0.0f,	1.0f	}
		},
		//13
		Vertice{
			glm::vec3{	1.0f,	1.0f,	-1.0f},
			glm::vec3{	0.0f,	1.0f,	-1.0f},
			glm::vec2{	1.0f,	0.0f}
		},
		//14
		Vertice{
			glm::vec3{	1.0f,  -1.0f,	-1.0f},
			glm::vec3{	1.0f,	0.0f,	-1.0f},
			glm::vec2{	1.0f,	1.0f	}
		},

		//lado inferior
		//9
		Vertice{
			glm::vec3{	-1.0f,	-1.0f,	-1.0f},
			glm::vec3{	1.0f,	0.0f,	0.0f},
			glm::vec2{	0.0f,	0.0f}
		},
		//10
		Vertice{
			glm::vec3{	1.0f,	-1.0f,	-1.0f},
			glm::vec3{	0.0f,	1.0f,	0.0f},
			glm::vec2{	1.0f,	0.0f}
		},
		//11
		Vertice{
			glm::vec3{	1.0f,  -1.0f,	1.0f},
			glm::vec3{	1.0f,	0.0f,	0.0f},
			glm::vec2{	1.0f,	1.0f	}
		},
		//12
		Vertice{
			glm::vec3{	-1.0f,  -1.0f,	1.0f},
			glm::vec3{	0.0f,	0.0f,	1.0f},
			glm::vec2{	0.0f,	1.0f	}
		},

		//lado superior
		//13
		Vertice{
			glm::vec3{	1.0f,	1.0f,	-1.0f},
			glm::vec3{	1.0f,	0.0f,	0.0f},
			glm::vec2{	0.0f,	0.0f}
		},
		//14
		Vertice{
			glm::vec3{	-1.0f,	1.0f,	-1.0f},
			glm::vec3{	0.0f,	1.0f,	0.0f},
			glm::vec2{	1.0f,	0.0f}
		},
		//15
		Vertice{
			glm::vec3{	-1.0f,   1.0f,	1.0f},
			glm::vec3{	1.0f,	0.0f,	0.0f},
			glm::vec2{	1.0f,	1.0f	}
		},
		//16
		Vertice{
			glm::vec3{	1.0f,  1.0f,	1.0f},
			glm::vec3{	0.0f,	0.0f,	1.0f},
			glm::vec2{	0.0f,	1.0f	}
		},
		
		//
		

	};

	//Definição do array de elementos que formam os trinagulos
	std::array<glm::ivec3, 12> Indices{
		glm::ivec3{	0,  1,	3},
		glm::ivec3{	3,  1,	2},

		glm::ivec3{	4,  5,	7},
		glm::ivec3{	7,  5,	6},

		glm::ivec3{	8,  9,	11},
		glm::ivec3{	11,  9,	10},

		glm::ivec3{	12, 13,	15},
		glm::ivec3{	15, 13,	14},

		glm::ivec3{	16,  17, 19},
		glm::ivec3{	19,  17, 18},

		glm::ivec3{	20, 21,	23},
		glm::ivec3{	23, 21,	22},
	};

	

	// Variável que vai conter o identificador do buffer de vértices
	GLuint VertexBuffer;

	// Gerar um identificador glGenBuffers(NUMERO DE BUFFER, INDETIFICADOR);
	glGenBuffers(1, &VertexBuffer);

	//Gerar a identificação do VertexBuffer (VBO) com o OpenGL 
	GLuint ElementBuffer = 0;
	glGenBuffers(1, &ElementBuffer);

	//Ativar o buffer de vértices, comandos vão afetar o VertexBuffer.
	//O buffer para onde vamos copiar os vertices do triangulo.
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

	// Passa para o OpenGL o ponteiro para os dados que serão copiados para GPU
	// basicamente copia os dados para a memória de vídeo
	glBufferData(GL_ARRAY_BUFFER, sizeof(Cube), Cube.data(), GL_STATIC_DRAW);

	//Copiar os dados para o bufffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices.data(), GL_STATIC_DRAW);

	//Gerar o Vertex Arrays Object VAO
	GLuint VAO;
	glGenVertexArrays(1, &VAO);

	// agora vamos habilitar o VAO
	glBindVertexArray(VAO);

	// Habilita as posições
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	glEnableVertexAttribArray(4);
	glEnableVertexAttribArray(5);
	glEnableVertexAttribArray(6);
	glEnableVertexAttribArray(7);
	glEnableVertexAttribArray(8);
	glEnableVertexAttribArray(9);
	glEnableVertexAttribArray(10);
	glEnableVertexAttribArray(11);
	glEnableVertexAttribArray(12);
	glEnableVertexAttribArray(13);
	glEnableVertexAttribArray(14);
	glEnableVertexAttribArray(15);
	glEnableVertexAttribArray(16);
	glEnableVertexAttribArray(17);
	glEnableVertexAttribArray(18);
	glEnableVertexAttribArray(19);
	glEnableVertexAttribArray(20);
	glEnableVertexAttribArray(21);
	glEnableVertexAttribArray(22);
	glEnableVertexAttribArray(23);
	glEnableVertexAttribArray(24);

	// Definindo os atributos
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), nullptr);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, Cor)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, UV)));

	glVertexAttribPointer(4, 7, GL_FLOAT, GL_FALSE, sizeof(Vertice), nullptr);
	glVertexAttribPointer(5, 7, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, Cor)));
	glVertexAttribPointer(6, 6, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, UV)));

	glVertexAttribPointer(8, 11, GL_FLOAT, GL_FALSE, sizeof(Vertice), nullptr);
	glVertexAttribPointer(9, 11, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, Cor)));
	glVertexAttribPointer(10, 10, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, UV)));

	// Shader com probema
	glVertexAttribPointer(12, 15, GL_FLOAT, GL_FALSE, sizeof(Vertice), nullptr);
	glVertexAttribPointer(13, 15, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, Cor)));
	glVertexAttribPointer(14, 14, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, UV)));

	// Definindo os atributos
	glVertexAttribPointer(16, 19, GL_FLOAT, GL_FALSE, sizeof(Vertice), nullptr);
	glVertexAttribPointer(17, 19, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, Cor)));
	glVertexAttribPointer(18, 18, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, UV)));

	// Definindo os atributos
	glVertexAttribPointer(20, 23, GL_FLOAT, GL_FALSE, sizeof(Vertice), nullptr);
	glVertexAttribPointer(21, 23, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, Cor)));
	glVertexAttribPointer(22, 22, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, UV)));


	// glBindBuffer(TIPO, BUFFER CRIADO);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBuffer);

	

	//Desabilita o VAO
	glBindVertexArray(0);

	return VAO;
}

//Gerando a malha que forma uma esfera
void GeraMalhaEsfera(GLuint resolucao, std::vector<Vertice>& Vertices
	, std::vector<glm::ivec3>& Indices) {
	//Limpar o vetor
	Vertices.clear();
	Indices.clear();

	//Armazendo o Pi e 2 PI para serrem usando no desenho da geometria da esfera
	//No espaço 3D
	constexpr float Pi = glm::pi<float>();
	constexpr float DoisPi = glm::two_pi<float>();

	//Calcular o inverso da resulução para gerar a textura UV da esfera
	const float InversoResolucao = 1.0f / static_cast<float>(resolucao - 1);

	//Loop para percorrer na horizontal eixo U
	for (GLuint UIndice = 0; UIndice < resolucao; ++UIndice)
	{
		//Gerando um número entee Zero e 1 no eixo U
		const float U = UIndice * InversoResolucao;
		//Calcular o parâmetro Phi aser usado como parâmetro (interpolação linerar)
		const float Phi = glm::mix(0.0f, DoisPi, U);

		//Loop no exio vertical, no exito V
		for (GLuint VIndice = 0; VIndice < resolucao; ++VIndice)
		{
			//Gerando um número entee Zero e 1 no eixo V
			const float V = VIndice * InversoResolucao;
			//Calcular o parâmetro Theta aser usado como parâmetro (interpolação linerar)
			const float Theta = glm::mix(0.0f, Pi, V);

			//Calculando a equação da esfera de raio 1, com o centro na origem do plano
			glm::vec3 PosicaoVertice{
				glm::sin(Theta) * glm::cos(Phi),
				glm::sin(Theta) * glm::sin(Phi),
				glm::cos(Theta)
			};
			//Calcular o vertice
			Vertice Vertice{
				PosicaoVertice,
				glm::vec3{ 1.0f,1.0f,1.0f },
				glm::vec2{ U, V}
			};
			//Armazenando o verticie calculado
			Vertices.push_back(Vertice);
		}
	}

	//Calculando os indices dos vertices que geram os triangulos
	for (GLuint U = 0; U < resolucao - 1; ++U) {
		for (GLuint V = 0; V < resolucao - 1; ++V) {
			GLuint P0 = U + V * resolucao;
			GLuint P1 = (U + 1) + V * resolucao;
			GLuint P2 = (U + 1) + (V + 1) * resolucao;
			GLuint P3 = U + (V + 1) * resolucao;

			Indices.push_back(glm::ivec3{ P0, P1, P3 });
			Indices.push_back(glm::ivec3{ P3, P1, P2 });
		}
	}

}

//Gerando o VAO da esfera
GLuint CarregarEsfera(GLuint& TotalVertices, GLuint& TotalIndices) {

	std::vector<Vertice> Vertices;
	std::vector<glm::ivec3> Triangulos;
	//Depois testa com 100
	GeraMalhaEsfera(50, Vertices, Triangulos);

	TotalVertices = Vertices.size();
	TotalIndices = Triangulos.size() * 3;

	//Gerando buffer de vértices e mandando para GPU ************
	GLuint VertexBuffer;
	glGenBuffers(1, &VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
	//Calcuando o tamanho do vertice
	GLsizeiptr size = Vertices.size() * sizeof(Vertice);
	glBufferData(GL_ARRAY_BUFFER, size, Vertices.data(), GL_STATIC_DRAW);

	//Gerando o buffer dos indices *******************
	GLuint ElementBuffer;
	glGenBuffers(1, &ElementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBuffer);
	//Calcuando o tamanho EM BYTES
	GLsizeiptr sizeIndice = TotalIndices * sizeof(GLuint);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeIndice, Triangulos.data(), GL_STATIC_DRAW);

	//Gerar o Vertex Arrays Object VAO
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Habilita as posições Coordenada e UV
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBuffer);

	// Informar pro Opengl onde estão os dados de cada VertexAttribArray
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), nullptr);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, Cor)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, sizeof(Vertice),
		reinterpret_cast<void*>(offsetof(Vertice, UV)));

	//Desabilita o VAO
	glBindVertexArray(0);

	return VAO;
}