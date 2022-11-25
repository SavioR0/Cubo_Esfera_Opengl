
FlyCamera Camera;
glm::vec2 PosicaoAnteriorCursor;
bool habilitarMovimentoMouse = false;
//Criar uma fun��o de callback para atualiar a imagem sempre
//que a resolu��o da janela for alterada
void Resize(GLFWwindow* window, int NovaLargura, int NovaAltura) {
	int Width = NovaLargura;
	int Heigth = NovaAltura;

	Camera.AspectRatio = static_cast<float>(Width) / Heigth;
	//Informar pro opengl o novo tamanho da janela
	glViewport(0, 0, Width, Heigth);
}


// Fun��es de callback do mouse
//Fun��o de callback, tem que ter estrutura padr�o
void MouseButtonCallback(GLFWwindow* Window, int Button, int Action, int Modifiers) {
	//Essa fun��o retorna quais botoes do mouse foram clicados.
	//Verifica se � bot�o esquerdo do mouse
	if (Button == GLFW_MOUSE_BUTTON_LEFT) {
		//Verifica qual a a��o relacizada com o bot�o esquerdo
		if (Action == GLFW_PRESS) {
			//Desabilita o curso quando estiver fora da window
			glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

			double X, Y;
			//Retorna a posi��o do mouse na tela
			glfwGetCursorPos(Window, &X, &Y);
			PosicaoAnteriorCursor = glm::vec2{ X, Y };
			habilitarMovimentoMouse = true;
		}
		// Verifica se a a��o foi encerrada
		else if (Action == GLFW_RELEASE) {
			//Habilita novamente o cursos, para ter o funcionamento normal
			glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			habilitarMovimentoMouse = false;
		}
	}
}

//Fun��o de callback, tem que ter estrutura padr�o
void MouseMotionCallback(GLFWwindow* Window, double X, double Y) {
	//Essa fun��o retorna a posi��o do mouse na tela

	if (habilitarMovimentoMouse) {
		glm::vec2 PosicaoAtualCursor{ X, Y };
		glm::vec2 Delta = PosicaoAnteriorCursor - PosicaoAtualCursor;

		Camera.OlharPara(-Delta.x, -Delta.y);

		PosicaoAnteriorCursor = PosicaoAtualCursor;
	}
}