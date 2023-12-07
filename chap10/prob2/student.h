struct student {
	int id; 
	char name[20]; 
	struct student *next; 
};
struct student *ptr;
ptr = (struct student *) malloc(sizeof(struct student));

