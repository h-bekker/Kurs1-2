struct B{
	virtual void empty() {}
};

struct D: B{
	int mas[30];
};

void putnull(B * pb){
	D *pd = (D*)pb;
	if(!pb)
		return;
	for(int i = 0; i <30; i++)
		pd->mas[i] = 0;
}

int main() {
	B* b;
	putnull(b);
	return 0;
	}
