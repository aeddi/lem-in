#include <xfunctions.h>

int main()
{
	t_xdata	*session;
	char	c;

	session = init_x_window("Lem-in", 300, 300);
	if (!session)
		return 1;

	set_background_color(session, 200, 200, 200);
	clear_window(session);
	set_drawing_color(session, 0, 200, 100);
	draw_line(session, (t_vector_2){100, 100}, (t_vector_2){200, 100});
	draw_line(session, (t_vector_2){200, 100}, (t_vector_2){150, 150});
	draw_line(session, (t_vector_2){150, 150}, (t_vector_2){100, 100});

	while(42)
	{
		c = wait_input(session);
		if (c == 'q')
			break;
	}
	return 0;
}
