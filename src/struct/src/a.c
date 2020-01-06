#include<stdio.h>
struct Vec2i{
	int x;
	int y;
};
struct Vec2f{
	float x;
	float y;
};
struct Employee{
	char name[80];
	char surname[80];
	int salary;
};
int main(int argc,char** argv){
	{
		/*stack*/
		struct Vec2i a;
		struct Vec2f b;
		a.x=1;
		a.y=2;
		fprintf(stdout,"x:%d\n",a.x);
		fprintf(stdout,"y:%d\n",a.y);
		b.x=0.1;
		b.y=0.2;
		fprintf(stdout,"x:%f\n",b.x);
		fprintf(stdout,"y:%f\n",b.y);
	}
	{
		/*dynamic*/
		struct Vec2i *a;
		struct Vec2f *b;
		a=(struct Vec2i*)malloc(sizeof(struct Vec2i));
		if(a!=NULL){
			a->x=1;
			a->y=2;
			fprintf(stdout,"x:%d\n",a->x);
			fprintf(stdout,"y:%d\n",a->y);
			free(a);
		}else{
			fprintf(stderr,"Failed to allocate\n");
			exit(1);
		}
		b=(struct Vec2f*)malloc(sizeof(struct Vec2f));
		if(b!=NULL){
			b->x=0.1;
			b->y=0.2;
			fprintf(stdout,"x:%f\n",b->x);
			fprintf(stdout,"y:%f\n",b->y);
			free(b);
		}else{
			fprintf(stderr,"Failed to allocate\n");
			exit(1);
		}

	}
	{
		/*initialization*/
		struct Employee a={
			"John",
			"Doe",
			1000
		};
		printf(
			"Employee:\nName:%s\nSurname:%s\nSalary:%d\n",
			a.name,
			a.surname,
			a.salary
		);
	}
	{
		/*inline*/
		struct {
			char a[80];
			int b
		} a[]={
			"foo",
			0,
			"bar",
			1,
			"baz",
			2
		};
		for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
			fprintf(
				stdout,
				"a:%s\nb:%d\n----------------------------------------\n",
				a[i].a,
				a[i].b
			);
		}
	}
	return 0;
}
