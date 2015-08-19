#include <xfunctions.h>

int main()
{
	t_xdata	*session;
	char	c;

	session = init_x_window("Lem-in", 1500, 1000, "-*-*-bold-r-*-*-15-*");
	if (!session)
		return 1;

	set_background_color(session, BLACK);
	clear_window(session);

	set_drawing_color(session, BLUE);
	draw_rectangle(session, (t_vector_2){50, 40}, (t_vector_2){90, 60}, 1);
	set_drawing_color(session, BLUE);
	draw_rectangle(session, (t_vector_2){200, 40}, (t_vector_2){90, 60}, 1);
	set_drawing_color(session, BLUE);
	draw_rectangle(session, (t_vector_2){350, 40}, (t_vector_2){90, 60}, 1);
	set_drawing_color(session, BLUE);
	draw_rectangle(session, (t_vector_2){500, 40}, (t_vector_2){90, 60}, 1);
	set_drawing_color(session, BLUE);
	draw_rectangle(session, (t_vector_2){650, 40}, (t_vector_2){90, 60}, 1);

	set_drawing_color(session, WHITE);
	draw_text(session, (t_vector_2){0, 0}, "ZOOOOB");

	while(42)
	{
		c = wait_input(session);
		if (c == 'q')
			break;
	}
	return 0;
}
