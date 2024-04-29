#pragma once
#include"Product.h"
#include"Queues.h"

class Order
{
public:
	Order() { pedido = *new Queues<Product*>(); }
	~Order() {}

	void AgregarProducto(int numeral, char nom[], float price, int tiempo) { pedido.enqueue(new Product(numeral, nom, price, tiempo)); }

	void CancelarPedido() {
		do {
			pedido.dequeue();
		} while (!pedido.isEmpty());

		cout << " El pedido se cancelo";
	}

	void Termino(Order colaped, int n) {

		Order aux = colaped;

		int i = n + 1;

		Product* temporal = aux.pedido.dequeue();

		if (temporal->getTime() == 0)
		{
			cout << "El producto " << i << " fue entregado" << endl;
		}
		else
		{
			cout << "El producto " << i << " sigue en proceso" << endl;
		}
		i;

		if (aux.pedido.isEmpty())
		{
			cout << " ya se comprobo el Pedido" << endl;
		}
		else
		{
			Termino(aux, i);
		}
	}

	void mostrarPedido() {
		Queues<Product*> aux = pedido;
		do
		{
			cout << aux.dequeue()->getEspecificaciones() << endl << endl;

		} while (!aux.isEmpty());

	}


private:
	Queues<Product*> pedido;

};

//chris