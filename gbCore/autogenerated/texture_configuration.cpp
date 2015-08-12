// autogenerated: do not add any changes
#include "texture_configuration.h"
namespace gb
{
bool texture_configuration::get_cubemap(void) const
{
const auto& iterator = m_attributes.find("/texture/is_cubemap");
assert(iterator != m_attributes.end());
bool value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_cubemap(bool is_cubemap)
{
configuration::set_attribute("/texture/is_cubemap", std::make_shared<configuration_attribute>(is_cubemap));
}
#endif
std::string texture_configuration::get_texture_filename(void) const
{
const auto& iterator = m_attributes.find("/texture/filename");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_texture_filename(std::string filename)
{
configuration::set_attribute("/texture/filename", std::make_shared<configuration_attribute>(filename));
}
#endif
std::string texture_configuration::get_texture_filename_x_positive(void) const
{
const auto& iterator = m_attributes.find("/texture/filename_x_positive");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_texture_filename_x_positive(std::string filename_x_positive)
{
configuration::set_attribute("/texture/filename_x_positive", std::make_shared<configuration_attribute>(filename_x_positive));
}
#endif
std::string texture_configuration::get_texture_filename_x_negative(void) const
{
const auto& iterator = m_attributes.find("/texture/filename_x_negative");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_texture_filename_x_negative(std::string filename_x_negative)
{
configuration::set_attribute("/texture/filename_x_negative", std::make_shared<configuration_attribute>(filename_x_negative));
}
#endif
std::string texture_configuration::get_texture_filename_y_positive(void) const
{
const auto& iterator = m_attributes.find("/texture/filename_y_positive");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_texture_filename_y_positive(std::string filename_y_positive)
{
configuration::set_attribute("/texture/filename_y_positive", std::make_shared<configuration_attribute>(filename_y_positive));
}
#endif
std::string texture_configuration::get_texture_filename_y_negative(void) const
{
const auto& iterator = m_attributes.find("/texture/filename_y_negative");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_texture_filename_y_negative(std::string filename_y_negative)
{
configuration::set_attribute("/texture/filename_y_negative", std::make_shared<configuration_attribute>(filename_y_negative));
}
#endif
std::string texture_configuration::get_texture_filename_z_positive(void) const
{
const auto& iterator = m_attributes.find("/texture/filename_z_positive");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_texture_filename_z_positive(std::string filename_z_positive)
{
configuration::set_attribute("/texture/filename_z_positive", std::make_shared<configuration_attribute>(filename_z_positive));
}
#endif
std::string texture_configuration::get_texture_filename_z_negative(void) const
{
const auto& iterator = m_attributes.find("/texture/filename_z_negative");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_texture_filename_z_negative(std::string filename_z_negative)
{
configuration::set_attribute("/texture/filename_z_negative", std::make_shared<configuration_attribute>(filename_z_negative));
}
#endif
std::string texture_configuration::get_render_technique_name(void) const
{
const auto& iterator = m_attributes.find("/texture/render_operation_name");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_render_technique_name(std::string render_operation_name)
{
configuration::set_attribute("/texture/render_operation_name", std::make_shared<configuration_attribute>(render_operation_name));
}
#endif
ui32 texture_configuration::get_sampler_index(void) const
{
const auto& iterator = m_attributes.find("/texture/sampler_index");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_sampler_index(ui32 sampler_index)
{
configuration::set_attribute("/texture/sampler_index", std::make_shared<configuration_attribute>(sampler_index));
}
#endif
GLenum texture_configuration::get_wrap_mode(void) const
{
const auto& iterator = m_attributes.find("/texture/wrap_mode");
assert(iterator != m_attributes.end());
GLenum value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_wrap_mode(GLenum wrap_mode)
{
configuration::set_attribute("/texture/wrap_mode", std::make_shared<configuration_attribute>(wrap_mode));
}
#endif
GLenum texture_configuration::get_mag_filter(void) const
{
const auto& iterator = m_attributes.find("/texture/mag_filter");
assert(iterator != m_attributes.end());
GLenum value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_mag_filter(GLenum mag_filter)
{
configuration::set_attribute("/texture/mag_filter", std::make_shared<configuration_attribute>(mag_filter));
}
#endif
GLenum texture_configuration::get_min_filter(void) const
{
const auto& iterator = m_attributes.find("/texture/min_filter");
assert(iterator != m_attributes.end());
GLenum value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void texture_configuration::set_min_filter(GLenum min_filter)
{
configuration::set_attribute("/texture/min_filter", std::make_shared<configuration_attribute>(min_filter));
}
#endif
void texture_configuration::serialize(pugi::xml_document& document, const std::string& path)
{
pugi::xpath_node node;
node = document.select_single_node((path + "/texture").c_str());
bool is_cubemap = node.node().attribute("is_cubemap").as_bool();
configuration::set_attribute("/texture/is_cubemap", std::make_shared<configuration_attribute>(is_cubemap));
std::string filename = node.node().attribute("filename").as_string();
configuration::set_attribute("/texture/filename", std::make_shared<configuration_attribute>(filename));
std::string filename_x_positive = node.node().attribute("filename_x_positive").as_string();
configuration::set_attribute("/texture/filename_x_positive", std::make_shared<configuration_attribute>(filename_x_positive));
std::string filename_x_negative = node.node().attribute("filename_x_negative").as_string();
configuration::set_attribute("/texture/filename_x_negative", std::make_shared<configuration_attribute>(filename_x_negative));
std::string filename_y_positive = node.node().attribute("filename_y_positive").as_string();
configuration::set_attribute("/texture/filename_y_positive", std::make_shared<configuration_attribute>(filename_y_positive));
std::string filename_y_negative = node.node().attribute("filename_y_negative").as_string();
configuration::set_attribute("/texture/filename_y_negative", std::make_shared<configuration_attribute>(filename_y_negative));
std::string filename_z_positive = node.node().attribute("filename_z_positive").as_string();
configuration::set_attribute("/texture/filename_z_positive", std::make_shared<configuration_attribute>(filename_z_positive));
std::string filename_z_negative = node.node().attribute("filename_z_negative").as_string();
configuration::set_attribute("/texture/filename_z_negative", std::make_shared<configuration_attribute>(filename_z_negative));
std::string render_operation_name = node.node().attribute("render_operation_name").as_string();
configuration::set_attribute("/texture/render_operation_name", std::make_shared<configuration_attribute>(render_operation_name));
ui32 sampler_index = node.node().attribute("sampler_index").as_uint();
configuration::set_attribute("/texture/sampler_index", std::make_shared<configuration_attribute>(sampler_index));
std::string wrap_mode = node.node().attribute("wrap_mode").as_string();
assert(g_string_to_glenum.find(wrap_mode) != g_string_to_glenum.end());
GLenum wrap_mode_enum = g_string_to_glenum.find(wrap_mode)->second;
configuration::set_attribute("/texture/wrap_mode", std::make_shared<configuration_attribute>(wrap_mode_enum));
std::string mag_filter = node.node().attribute("mag_filter").as_string();
assert(g_string_to_glenum.find(mag_filter) != g_string_to_glenum.end());
GLenum mag_filter_enum = g_string_to_glenum.find(mag_filter)->second;
configuration::set_attribute("/texture/mag_filter", std::make_shared<configuration_attribute>(mag_filter_enum));
std::string min_filter = node.node().attribute("min_filter").as_string();
assert(g_string_to_glenum.find(min_filter) != g_string_to_glenum.end());
GLenum min_filter_enum = g_string_to_glenum.find(min_filter)->second;
configuration::set_attribute("/texture/min_filter", std::make_shared<configuration_attribute>(min_filter_enum));
}
#if defined(__EDITOR__)
void texture_configuration::deserialize(pugi::xml_node& node)
{
pugi::xml_attribute attribute;
attribute = node.append_attribute("is_cubemap");
bool is_cubemap = texture_configuration::get_cubemap();
attribute.set_value(is_cubemap);
attribute = node.append_attribute("filename");
std::string filename = texture_configuration::get_texture_filename();
attribute.set_value(filename.c_str());
attribute = node.append_attribute("filename_x_positive");
std::string filename_x_positive = texture_configuration::get_texture_filename_x_positive();
attribute.set_value(filename_x_positive.c_str());
attribute = node.append_attribute("filename_x_negative");
std::string filename_x_negative = texture_configuration::get_texture_filename_x_negative();
attribute.set_value(filename_x_negative.c_str());
attribute = node.append_attribute("filename_y_positive");
std::string filename_y_positive = texture_configuration::get_texture_filename_y_positive();
attribute.set_value(filename_y_positive.c_str());
attribute = node.append_attribute("filename_y_negative");
std::string filename_y_negative = texture_configuration::get_texture_filename_y_negative();
attribute.set_value(filename_y_negative.c_str());
attribute = node.append_attribute("filename_z_positive");
std::string filename_z_positive = texture_configuration::get_texture_filename_z_positive();
attribute.set_value(filename_z_positive.c_str());
attribute = node.append_attribute("filename_z_negative");
std::string filename_z_negative = texture_configuration::get_texture_filename_z_negative();
attribute.set_value(filename_z_negative.c_str());
attribute = node.append_attribute("render_operation_name");
std::string render_operation_name = texture_configuration::get_render_technique_name();
attribute.set_value(render_operation_name.c_str());
attribute = node.append_attribute("sampler_index");
ui32 sampler_index = texture_configuration::get_sampler_index();
attribute.set_value(sampler_index);
attribute = node.append_attribute("wrap_mode");
GLenum wrap_mode_enum = texture_configuration::get_wrap_mode();
assert(g_enumGLToString.find(wrap_modeEnum) != g_enumGLToString.end());
std::string wrap_mode = g_glenum_to_string.find(wrap_mode_enum)->second;
attribute.set_value(wrap_mode.c_str());
attribute = node.append_attribute("mag_filter");
GLenum mag_filter_enum = texture_configuration::get_mag_filter();
assert(g_enumGLToString.find(mag_filterEnum) != g_enumGLToString.end());
std::string mag_filter = g_glenum_to_string.find(mag_filter_enum)->second;
attribute.set_value(mag_filter.c_str());
attribute = node.append_attribute("min_filter");
GLenum min_filter_enum = texture_configuration::get_min_filter();
assert(g_enumGLToString.find(min_filterEnum) != g_enumGLToString.end());
std::string min_filter = g_glenum_to_string.find(min_filter_enum)->second;
attribute.set_value(min_filter.c_str());
}
#endif
void texture_configuration::serialize(pugi::xml_document& document, pugi::xpath_node& node)
{
bool is_cubemap = node.node().attribute("is_cubemap").as_bool();
configuration::set_attribute("/texture/is_cubemap", std::make_shared<configuration_attribute>(is_cubemap));
std::string filename = node.node().attribute("filename").as_string();
configuration::set_attribute("/texture/filename", std::make_shared<configuration_attribute>(filename));
std::string filename_x_positive = node.node().attribute("filename_x_positive").as_string();
configuration::set_attribute("/texture/filename_x_positive", std::make_shared<configuration_attribute>(filename_x_positive));
std::string filename_x_negative = node.node().attribute("filename_x_negative").as_string();
configuration::set_attribute("/texture/filename_x_negative", std::make_shared<configuration_attribute>(filename_x_negative));
std::string filename_y_positive = node.node().attribute("filename_y_positive").as_string();
configuration::set_attribute("/texture/filename_y_positive", std::make_shared<configuration_attribute>(filename_y_positive));
std::string filename_y_negative = node.node().attribute("filename_y_negative").as_string();
configuration::set_attribute("/texture/filename_y_negative", std::make_shared<configuration_attribute>(filename_y_negative));
std::string filename_z_positive = node.node().attribute("filename_z_positive").as_string();
configuration::set_attribute("/texture/filename_z_positive", std::make_shared<configuration_attribute>(filename_z_positive));
std::string filename_z_negative = node.node().attribute("filename_z_negative").as_string();
configuration::set_attribute("/texture/filename_z_negative", std::make_shared<configuration_attribute>(filename_z_negative));
std::string render_operation_name = node.node().attribute("render_operation_name").as_string();
configuration::set_attribute("/texture/render_operation_name", std::make_shared<configuration_attribute>(render_operation_name));
ui32 sampler_index = node.node().attribute("sampler_index").as_uint();
configuration::set_attribute("/texture/sampler_index", std::make_shared<configuration_attribute>(sampler_index));
std::string wrap_mode = node.node().attribute("wrap_mode").as_string();
assert(g_string_to_glenum.find(wrap_mode) != g_string_to_glenum.end());
GLenum wrap_mode_enum = g_string_to_glenum.find(wrap_mode)->second;
configuration::set_attribute("/texture/wrap_mode", std::make_shared<configuration_attribute>(wrap_mode_enum));
std::string mag_filter = node.node().attribute("mag_filter").as_string();
assert(g_string_to_glenum.find(mag_filter) != g_string_to_glenum.end());
GLenum mag_filter_enum = g_string_to_glenum.find(mag_filter)->second;
configuration::set_attribute("/texture/mag_filter", std::make_shared<configuration_attribute>(mag_filter_enum));
std::string min_filter = node.node().attribute("min_filter").as_string();
assert(g_string_to_glenum.find(min_filter) != g_string_to_glenum.end());
GLenum min_filter_enum = g_string_to_glenum.find(min_filter)->second;
configuration::set_attribute("/texture/min_filter", std::make_shared<configuration_attribute>(min_filter_enum));
}
}
