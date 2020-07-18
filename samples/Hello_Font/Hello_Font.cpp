
#include <iostream>
#include "es_util.h"
#include "tiny_font_stash.h"
#include "tiny_primitive_renderer.h"
#include "tiny_fontstashcallbacks.h"

typedef struct {
    // Handle to a program object
    sth_stash *stash;
    RenderCallbacks *m_renderCallbacks;
    TinyGLPrimitiveRenderer *m_primRenderer;
    int droidRegular, droidItalic, droidBold, droidChinese;
} UserData;

int loadFonts(struct sth_stash *stash, int *droidRegular, int *droidItalic, int *droidBold, int *droidChinese) {
    // Load the first truetype font from memory (just because we can).
    FILE *fp = fopen("DroidSerif-Regular.ttf", "rb");
    if (!fp) return 0;
    fseek(fp, 0, SEEK_END);
    int datasize = (int) ftell(fp);
    fseek(fp, 0, SEEK_SET);
    unsigned char *data = (unsigned char *) malloc(datasize);
    if (!data) return 0;
    fread(data, 1, datasize, fp);
    fclose(fp);
    fp = 0;
    if (!(*droidRegular = sth_add_font_from_memory(stash, data))) return 0;
    // Load the remaining truetype fonts directly.
    if (!(*droidItalic = sth_add_font(stash, "DroidSerif-Italic.ttf"))) return 0;
    if (!(*droidBold = sth_add_font(stash, "DroidSerif-Bold.ttf"))) return 0;
    if (!(*droidChinese = sth_add_font(stash, "SourceHanSansCN-Normal.otf"))) return 0;
    return 1;
}

///
// Initialize the shader and program object
//
//
int Init(ESContext *esContext, int argc, char *argv[]) {
    UserData *userData = (UserData *) (esContext->userData);
    // Store the program object
    userData->m_primRenderer = new TinyGLPrimitiveRenderer(esContext->width, esContext->height);
    userData->m_primRenderer->set_screen_size(esContext->width, esContext->height);
    userData->m_renderCallbacks = new OpenGLRenderCallbacks(userData->m_primRenderer);
    userData->stash = sth_create(
            512, 512, userData->m_renderCallbacks);
    if (!userData->stash) fprintf(stderr, "Could not create stash.\n");
    loadFonts(userData->stash, &userData->droidRegular, &userData->droidItalic, &userData->droidBold,
              &userData->droidChinese);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    return TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
void Draw(ESContext *esContext) {
    UserData *userData = (UserData *) (esContext->userData);
    sth_stash *stash = userData->stash;
    // Set the viewport
    glViewport(0, 0, esContext->width, esContext->height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float sx = 50, sy = 150, lh;
    float dx = sx, dy = sy, scale = 3.0f;
    int screenWidth = userData->m_primRenderer->get_screen_width();
    int screenHeight = userData->m_primRenderer->get_screen_height();
    sth_begin_draw(stash);
    float color_white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    sth_draw_text(stash, userData->droidRegular, 24.0f * scale, dx, dy, "The quick ", &dx, screenWidth, screenHeight,
                  false, 1., color_white);
    sth_draw_text(stash, userData->droidItalic, 48.0f * scale, dx, dy, "brown ", &dx, screenWidth, screenHeight,
                  false, 1., color_white);
    sth_draw_text(stash, userData->droidRegular, 24.0f * scale, dx, dy, "fox ", &dx, screenWidth, screenHeight,
                  false, 1., color_white);
    sth_vmetrics(stash, userData->droidItalic, 24 * scale, NULL, NULL, &lh);
    sth_end_draw(stash);
    dx = sx;
    dy += lh * 1.2f;
    sth_begin_draw(stash);
    float color_red[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    sth_draw_text(stash, userData->droidItalic, 24.0f * scale, dx, dy, "jumps over ", &dx, screenWidth, screenHeight,
                  false, 1., color_red);
    sth_draw_text(stash, userData->droidBold, 24.0f * scale, dx, dy, "the lazy ", &dx, screenWidth, screenHeight,
                  false, 1., color_red);
    sth_draw_text(stash, userData->droidRegular, 24.0f * scale, dx, dy, "dog.", &dx, screenWidth, screenHeight,
                  false, 1., color_red);
    sth_end_draw(stash);

    dx = sx;
    dy += lh * 1.2f;
    sth_begin_draw(stash);
    float color_green[4] = {.0f, 1.f, 0.0f, 1.0f};
    sth_draw_text(stash, userData->droidRegular, 12.0f * scale, dx, dy,
                  "Now is the time for all good men to come to the aid of the party.", &dx, screenWidth, screenHeight,
                  false, 1., color_green);
    sth_vmetrics(stash, userData->droidItalic, 12 * scale, NULL, NULL, &lh);
    sth_end_draw(stash);

    dx = sx;
    dy += lh * 1.2f * 2;
    sth_begin_draw(stash);
    float color_yellow[4] = {1.0f, 1.0f, 0.0f, 1.0f};
    sth_draw_text(stash, userData->droidItalic, 18.0f * scale, dx, dy, "Ég get etið gler án þess að meiða mig.", &dx,
                  screenWidth, screenHeight,
                  false, 1., color_yellow);
    sth_vmetrics(stash, userData->droidItalic, 18 * scale, NULL, NULL, &lh);
    dx = sx;
    dy += lh * 1.2f;

    sth_draw_text(stash, userData->droidChinese, 18.0f * scale, dx, dy, "我可以吃屎，它真香。", &dx, screenWidth, screenHeight,
                  false, 1., color_yellow);
    dx = sx;
    dy += lh * 1.2f * 2;
    sth_end_draw(stash);
}

void Shutdown(ESContext *esContext) {
    UserData *userData = (UserData *) (esContext->userData);
    sth_delete(userData->stash);
    delete userData->m_primRenderer;
    delete userData->m_renderCallbacks;
}

// https://github.com/google-research/tiny-differentiable-simulator
// https://github.com/yarston/fontstash
// https://github.com/hjanetzek/alfons
// https://github.com/tangrams/fontstash-es
int esMain(ESContext *esContext, int argc, char *argv[]) {
    esContext->userData = malloc(sizeof(UserData));
    esCreateWindow(esContext, "Hello Font", 1280, 720, ES_WINDOW_RGB);
    if (!Init(esContext, argc, argv)) {
        return GL_FALSE;
    }
    esRegisterShutdownFunc(esContext, Shutdown);
    esRegisterDrawFunc(esContext, Draw);
    return GL_TRUE;
}
