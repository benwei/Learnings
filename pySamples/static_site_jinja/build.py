from staticjinja import make_site

def get_temps():
    """Generate knights of the round table."""
    temp_vars = [
            'item a',
            'item b',
            'item c',
            ]
    return {
            'vars': temp_vars,
            'static_root': '/static'
           }

if __name__ == "__main__":
    site = make_site(contexts=[
        ('index.html', get_temps),
        ])
    site.render(use_reloader=False)
