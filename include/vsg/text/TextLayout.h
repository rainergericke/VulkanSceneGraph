#pragma once

/* <editor-fold desc="MIT License">

Copyright(c) 2020 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#include <vsg/core/Array.h>
#include <vsg/core/Inherit.h>
#include <vsg/text/Font.h>

namespace vsg
{
    struct TextQuad
    {
        vec3 vertices[4];
        vec2 texcoords[4];
        vec4 colors[4];
        vec4 outlineColors[4];
        float outlineWidths[4];
        vec3 normal;
    };

    using TextQuads = std::vector<TextQuad>;

    class VSG_DECLSPEC TextLayout : public Inherit<Object, TextLayout>
    {
    public:
        virtual void layout(const Data* text, const Font& font, TextQuads& texQuads) = 0;
    };
    VSG_type_name(vsg::TextLayout);

    class VSG_DECLSPEC LeftAlignment : public Inherit<TextLayout, LeftAlignment>
    {
    public:
        void read(Input& input) override;
        void write(Output& output) const override;

        vec3 position = vec3(0.0f, 0.0f, 0.0f);
        vec3 horizontal = vec3(1.0f, 0.0f, 0.0f);
        vec3 vertical = vec3(0.0f, 1.0f, 0.0f);
        vec4 color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
        vec4 outlineColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
        float outlineWidth = 0.0f;

        void layout(const Data* text, const Font& font, TextQuads& texQuads) override;
    };
    VSG_type_name(vsg::LeftAlignment);

} // namespace vsg
