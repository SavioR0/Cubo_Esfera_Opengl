//Nativas do C e C++
#include "Atividade3.h"

void view(bool isCube) {
	setlocale(LC_ALL, "pt_BR");
	//Inicializando a biblioteca do GLFW 
	assert(glfwInit() == GLFW_TRUE);
	//Construindo a janela
	GLFWwindow* window = glfwCreateWindow(Width, Heigth, "CG com OpenGL", nullptr, nullptr);
	//Verificar se a janela é nula
	assert(window);

	//Cadastrar callbacks no GLFW
	glfwSetMouseButtonCallback(window, MouseButtonCallback);
	glfwSetCursorPosCallback(window, MouseMotionCallback);
	glfwSetFramebufferSizeCallback(window, Resize);

	//Definindo a janela de contexto
	glfwMakeContextCurrent(window);

	//Desabilita a sircronização de FPS entre o processamenro e monitor
	//glfwSwapInterval(1);

	//inicializa o GLEW
	int statusGlwInit = glewInit();
	std::cout << statusGlwInit << std::endl;
	assert(glewInit() == GLEW_OK);

	//Verificar a versão do OpenGL que está sendo usando
	GLint GLMajorVersion = 0;
	GLint GLMinorVersion = 0;

	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);

	//Atualizando as configurações da janela
	Resize(window, Width, Heigth);

	//Carregando os Shaders
	GLuint ProgramaId = LoadShaders("shaders/triangle_vert.glsl", "shaders/triangle_frag.glsl");

	//Carregando texturas
	GLuint TexturaId = carregarTextura("textures/mundo.jpg");

	//Carregando a geometria
	GLuint QuadVAO = Cube();

	//Carregando a geometria da esfera
	GLuint EsferaTotalVertices = 0;
	GLuint EsferaTotalIndices = 0;
	GLuint EsferaVAO = CarregarEsfera(EsferaTotalVertices, EsferaTotalIndices);

	//Criando o Model
	// Podemos já aplicar uma transformação no model
	glm::mat4 MatrizIdentidade = glm::identity<glm::mat4>();
	//constexpr float AnguloDeRotacao = glm::radians(-90.0);
	//glm::vec3 EixoDeRotacao{ 1, 0, 0 };
	//glm::mat4 MatrizModel = glm::rotate(MatrizIdentidade, AnguloDeRotacao, EixoDeRotacao);
	glm::mat4 MatrizModel = MatrizIdentidade;

	//Definir cor de fundo
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	//Tempo de atualizado dos frames
	double  TempoAtualizadoFrameAnterior = glfwGetTime();

	//Habilitar o Backface culling
	glEnable(GL_CULL_FACE); // Trocar para ver o fundo da esfera glDiable(GL_CULL_FACE)
	glCullFace(GL_BACK);

	//Construindo o loop de eventos
	while (!glfwWindowShouldClose(window)) {
		//Calculando o DeltaTime
		double  TempoAtualizadoFrameAtual = glfwGetTime();
		double DeltaTime = TempoAtualizadoFrameAtual - TempoAtualizadoFrameAnterior;
		if (DeltaTime > 0) {
			TempoAtualizadoFrameAnterior = TempoAtualizadoFrameAtual;
		}
		// Limpar o Buffer de cor
		glClear(GL_COLOR_BUFFER_BIT);

		// Ativar o Shader criado
		glUseProgram(ProgramaId);

		// Calculando a MVP dinamicamente
		glm::mat4 MatrizViewProjection = Camera.GetViewProjection();
		glm::mat4 ModelViewProjection = MatrizViewProjection * MatrizModel;

		//Obter a localização da MPV
		GLint ModelViewProjectionLoc = glGetUniformLocation(ProgramaId, "ModelViewProjection");
		//Definindo os valores do Uniform
		glUniformMatrix4fv(ModelViewProjectionLoc, 1, GL_FALSE, glm::value_ptr(ModelViewProjection));

		//Habilitando a Textura no indice 0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, TexturaId);

		GLint TextureSamplerLoc = glGetUniformLocation(ProgramaId, "TextureSampler");
		glUniform1i(TextureSamplerLoc, 0);

		//Passando o objeto que será desenhado

		if (isCube) {
			glBindVertexArray(QuadVAO);
		}
		else {
			glBindVertexArray(EsferaVAO);
		}
		// Definir o tamanho dos pontos a serem desenhados
		glPointSize(10.0f);
		//Definindo a largura da linha
		glLineWidth(10.0f);

		//Definindo o modo de desenho
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL | GL_LINE);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//Desenhando os pontos da esfera
		// Agora vamos deixar de senhar o esfera usando os pontos (glDrawArrays)
		// Para desenhar usando os Elements = Triangulos (glDrawElements)
		//glDrawArrays(GL_POINTS,0, EsferaTotalVertices);
		glDrawElements(GL_TRIANGLES, EsferaTotalIndices, GL_UNSIGNED_INT, nullptr);

		//Desabilitando o 
		glBindVertexArray(QuadVAO);
		//glBindVertexArray(0);

		//Desabilita o programa
		glUseProgram(0);

		glfwPollEvents();
		glfwSwapBuffers(window);

		// Capturando eventor do teclado
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			Camera.MoverPraFrente(1.0f * DeltaTime);
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			Camera.MoverPraFrente(-1.0f * DeltaTime);
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			Camera.MoverPraDireita(1.0f * DeltaTime);
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			Camera.MoverPraDireita(-1.0f * DeltaTime);
		}
	}

	glDeleteVertexArrays(1, &QuadVAO);

	//Finaliza a biblioteca GLFW
	glfwTerminate();
}


int main() {
	view(false);
	view(true);
	return 0;
}
